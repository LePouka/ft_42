/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/14 17:09:48 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	size_t		i;
	size_t		llen;
	char		*line;
	static char	*bank;
	void		buff[BUFFER_SIZE];

	if !fd
		return (NULL);
	bank = read (fd, buff, BUFFER_SIZE);
	llen = linelen(bank);
}
