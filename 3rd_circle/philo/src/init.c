/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/10 17:15:04 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int argc, char **argv, t_data *data)
{
	data->nbr_of_philo = atouille(argv[1]);
	if (data->nbr_of_philo < 0)
		return (1);
	data->time_to_die = atouille(argv[2]);
	if (data->time_to_die < 0)
		return (2);
	data->time_to_eat = atouille(argv[3]);
	if (data->time_to_eat < 0)
		return (3);
	data->time_to_sleep = atouille(argv[4]);
	if (data->time_to_sleep < 0)
		return (4);
	data->nbr_philo_eat = -1;
	if (argc == 5)
	{
		data->nbr_philo_eat = atouille(argv[5]);
		if (data->nbr_philo_eat < 0)
			return (5);
	}
	data->start_time = get_time_in_ms();
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	data->all_forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
	if (!data->all_forks)
		error("Cannot Malloc Forks", data);
	data->philo = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!data->philo)
		error("Cannot Malloc Philo", data);
	i = 0;
	while (i < data->nbr_ot_philo)
	{
		if (pthread_mutex_init(&data->all_forks[i], NULL))
			error("Cannot Init Mutex", data);
		i++;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < nbr_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_meals = 0;
		data->philo[i].time_last_meal = 0;
	}
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_of_philo)
	{
		if (pthread_create(&philo->philo[i], NULL, &routine, (void *)philo))
		{
			destroy_fork((*philo));
			return ;
		}
		i++;
	}
}
