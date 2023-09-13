/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:35:47 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/13 19:45:18 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_sprite sprite, t_vars vars, t_map map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (map.map[x])
	{
		y = 0;
		while (map.map[x][y])
		{
			if (map.map[x][y] == '1')
				print_sprite(vars, sprite.wall, y * 80, x * 80);
			else if (map.map[x][y] == '0')
				print_sprite(vars, sprite.floor, y * 80, x * 80);
			else if (map.map[x][y] == 'C')
				print_sprite(vars, sprite.collectible, y * 80, x * 80);
			else if (map.map[x][y] == 'E')
				print_sprite(vars, sprite.exit, y * 80, x * 80);
			else if (map.map[x][y] == 'P')
				print_sprite(vars, sprite.character, y * 80, x * 80);
			y++;
		}
		x++;
	}
}