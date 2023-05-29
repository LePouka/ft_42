/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:36:45 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/23 17:41:24 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_vars *vars)
{
	ft_clear_vars(vars);
	return (0);
}

int	ft_handle_key(int key, t_vars *vars)
{
	/*
	if (key == keycode pour fleche droite)
		tu vas swap ton sprite char avec ton sprite sol
	-->check que ca soit pas un mur
	*/
	if (key == 65307)
		ft_clear_vars(vars);
	ft_printf("la touche enfoncee est : { %d }\n", key);
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