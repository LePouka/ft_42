/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:36:45 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/08 16:08:20 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_vars *vars)
{
	ft_clear_vars(vars);
	return (0);
}

// if (key == keycode pour fleche droite)
// 	tu vas swap ton sprite char avec ton sprite sol
// -->check que ca soit pas un mur
int	ft_handle_key(int key, t_vars *vars)
{
	if (key == 65307)
		ft_clear_vars(vars);
	ft_printf_fd(1, "la touche enfoncee est : { %d }\n", key);
	return (0);
}

int	ft_clear_vars(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

size_t	malloc_strlcpy(char *dst, const char *src, size_t size)
{
	dst = malloc((sizeof(char) * size + 1));
	if (!dst)
		return (0);
	return (ft_strlcpy(dst, src, size));
}
