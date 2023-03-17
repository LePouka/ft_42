/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:02:56 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/17 13:36:48 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	bool	test;
	t_list	*stocka;

	if (argc < 2)
		return (0);
	test = checkarg(argv);
	if (!test)
		return (ft_putstr_fd("Error\n", 1), 0);
	stocka = atoi_list(argc, argv);
	if (!stocka)
		return (ft_putstr_fd("Error\n", 1), 0);
	test = checksamearg(stocka);
	if (!test)
		return (lst_clean(&stocka), ft_putstr_fd("Error\n", 1), 0);
	push_swap(stocka);
	return (0);
}