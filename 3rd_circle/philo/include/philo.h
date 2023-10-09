/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:33:22 by raphael           #+#    #+#             */
/*   Updated: 2023/10/09 14:16:47 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/******************************************************************************/
/*   STRUCTURES                                                               */
/******************************************************************************/
typedef struct s_data {
	int				nbr_of_philo;
	int				nbr_each_philo_must_eat;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				philo_died;
	pthread_t		philo_died_m;
	pthread_mutex_t	*all_forks;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo {
	pthread_t			*philo;
	int					left_fork;
	int					right_fork;
	int					nb_meals_v;
	pthread_mutex_t		nb_meals_m;
	long				time_last_meal_v;
	pthread_mutex_t		time_last_meal_m;
	struct s_data		*data;
}	t_philo;

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
int		atouille(char *str);
int		dying(t_data data);
int		eating(t_data data);
int		thinking(t_data data);
int		sleeping(t_data data);
int		init_philo(t_philo *philo);
int		init_data(int argc, char **argv, t_data *data);
long	get_time_in_ms(void);
void	destroy_fork(t_philo philo);
void	init_threads(t_philo *philo);
void	join_threads(t_philo *philo);
void	*routine(void *philou);

#endif
