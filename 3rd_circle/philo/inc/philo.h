/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:33:22 by raphael           #+#    #+#             */
/*   Updated: 2023/10/19 01:54:48 by raphael          ###   ########.fr       */
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
# include <limits.h>

/******************************************************************************/
/*   STRUCTURES                                                               */
/******************************************************************************/
typedef struct s_data {
	int				nb_philo;
	int				nb_philo_eat;
	int				eat_v;
	int				stop_v;
	long long int	start_time;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	pthread_mutex_t	*all_forks;
	pthread_mutex_t	eat_m;
	pthread_mutex_t	stop_m;
	pthread_mutex_t	start_time_m;
	pthread_mutex_t	print;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo {
	int				id;
	long			nb_meals;
	long long int	time_last_meal;
	pthread_t		philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_m;
	struct s_data	*data;
}	t_philo;

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
int				is_full(t_data *data);
int				is_stop(t_data *data);
int				init_forks(t_data *data);
int				init_philo(t_data *data);
int				ft_atoi(const char *nptr);
int				init_threads(t_data *data);
int				join_threads(t_data *data);
int				error(char *s, t_data *data);
int				init_args(int argc, char **argv, t_data *data);
void			clear(t_data *dat);
void			*routine(void *philou);
void			*routinette(void *tmp);
void			philo_one(t_philo *philo);
void			destroy_fork(t_data *data);
void			take_forks(t_philo *philo);
void			ft_print(char *s, t_philo *philo);
void			ft_usleep(long long int time, t_data *data);
long long int	get_time_in_ms(void);

#endif
