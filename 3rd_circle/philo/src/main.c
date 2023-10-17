/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:27:39 by raphael           #+#    #+#             */
/*   Updated: 2023/10/17 18:14:43 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (init_args(ac, av, &data))
			return (1);
		if (init_forks(&data))
			return (2);
		if (init_philo(&data))
			return (3);
		if (init_threads(&data))
			return (4);
		if (join_threads(&data))
			return (5);
		destroy_fork(&data);
		clear(&data);
	}
	return (0);
}
