/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/24 16:57:05 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_sprite	sprite;

	(void) argv;
	if (argc != 2)
		return (ft_printf("/!\\ Error /!\\\n--- Argc != 2 ---\n"), 1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "so_long");
	vars.height = 80;
	vars.width = 80;
	sprite = init_sprite();
	print_sprite(vars, sprite.collectible, 0, 0);
	mlx_key_hook(vars.win, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 1L << 17, &close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}