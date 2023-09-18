/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/18 11:26:08 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vrs;
	t_sprite	sprite;

	if (argc != 2)
		error("Bad Arguments\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error("Invalid Path\n");
	vrs.m = read_map(open(argv[1], O_RDONLY, 0777));
	check_map(&vrs.m);
	vrs.mlx = mlx_init();
	vrs.win = mlx_new_window(vrs.mlx, vrs.m.y * 80, vrs.m.x * 80, "so_long");
	vrs.width = 80 * vrs.m.p_y;
	vrs.height = 80 * vrs.m.p_x;
	ft_printf_fd(1, "width (y) = %d height (x) = %d\n", vrs.width / 80, vrs.height / 80);
	sprite = init_sprite();
	print_map(sprite, &vrs, vrs.m);
	clear(vrs.m.map);
	mlx_key_hook(vrs.win, ft_handle_key, &vrs);
	mlx_hook(vrs.win, 17, 1l << 17, &close_window, &vrs);
	mlx_loop(vrs.mlx);
	return (0);
}
