/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/19 01:59:28 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo <= 0)
		return (printf("Error: Bad Arguments\n"), 1);
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die < 0)
		return (printf("Error: Bad Arguments\n"), 1);
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat < 0)
		return (printf("Error: Bad Arguments\n"), 1);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep < 0)
		return (printf("Error: Bad Arguments\n"), 1);
	if (argc == 6)
	{
		data->nb_philo_eat = ft_atoi(argv[5]);
		if (data->nb_philo_eat <= 0)
			return (printf("Error: Bad Arguments\n"), 1);
	}
	else
		data->nb_philo_eat = -1;
	data->eat_v = 0;
	data->stop_v = 0;
	return (0);
}

void	init_rl_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].left_fork = &data->all_forks[i];
		if (i == data->nb_philo - 1)
			data->philo[i].right_fork = &data->all_forks[0];
		else
			data->philo[i].right_fork = &data->all_forks[i + 1];
		i++;
	}
}

int	init_forks(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		error("Cannot Malloc Philo", data);
	data->all_forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->all_forks)
		error("Cannot Malloc Forks", data);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->all_forks[i], NULL))
			error("Cannot Init Mutex", data);
		i++;
	}
	init_rl_forks(data);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].nb_meals = 0;
		data->philo[i].time_last_meal = 0;
		data->philo[i].data = data;
		if (pthread_mutex_init(&data->philo[i].meal_m, NULL))
			error("Cannot Init Mutex", data);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL))
		error("Cannot Init Mutex", data);
	if (pthread_mutex_init(&data->eat_m, NULL))
		error("Cannot Init Mutex", data);
	if (pthread_mutex_init(&data->stop_m, NULL))
		error("Cannot Init Mutex", data);
	if (pthread_mutex_init(&data->start_time_m, NULL))
		error("Cannot Init Mutex", data);
	return (0);
}

int	init_threads(t_data *data)
{
	int			i;
	pthread_t	t1;

	i = 0;
	pthread_mutex_lock(&data->start_time_m);
	data->start_time = get_time_in_ms();
	// pthread_mutex_unlock(&data->start_time_m);
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].philo, NULL, \
			&routine, &data->philo[i]))
			error("Cannot Create Thread", data);
		i++;
	}
	if (data->nb_philo != 1)
	{
		if (pthread_create(&t1, NULL, &routinette, (void *)data))
			error("Cannot Create Thread", data);
		pthread_mutex_unlock(&data->start_time_m);
		if (pthread_join(t1, NULL))
			error("Cannot Join Thread", data);
	}
	else
		pthread_mutex_unlock(&data->start_time_m);
	return (0);
}
