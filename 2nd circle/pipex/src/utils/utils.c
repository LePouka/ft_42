/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:42 by rtissera          #+#    #+#             */
/*   Updated: 2023/06/27 08:46:37 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	execificator(char *cmd, char **env)
{
	char	*path;
	char	**scmd;

	scmd = ft_split(cmd, ' ');
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)) != NULL)
		path = scmd[0];
	else
		path = get_path(scmd[0], env);
	if (!path)
		path = cmd;
	if (execve(path, scmd, env) == -1)
	{
		iwanttobreakfree(scmd);
		error();
	}
}

void	iwanttobreakfree(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

char	*get_path(char *scmd, char **env)
{
	int		i;
	int		j;
	char	*path;
	char	*execpath;
	char	**paths;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	j = 0;
	while (paths[j])
	{
		path = ft_strjoin(paths[j], "/");
		execpath = ft_strjoin(path, scmd);
		free(path);
		if (access(execpath, F_OK | X_OK) == 0)
			return (execpath);
		free(execpath);
	}
	iwanttobreakfree(paths);
	return (NULL);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
