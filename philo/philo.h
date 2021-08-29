/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:21:36 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/29 18:07:38 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_data
{
	long int		num;
	long int		die_time;
	long int		eat_time;
	long int		sleep_time;
	long int		meals_n;
	int				death_i;
	pthread_t		*pthreads;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*dead_m;
	pthread_mutex_t	*print_m;
	pthread_mutex_t	*start_m;
	int				is_food_limited;
	int				is_ready;
}				t_data;

typedef struct s_philo
{
	int				index;
	size_t			last_meal;
	size_t			start;
	pthread_mutex_t	*fork_one;
	pthread_mutex_t	*fork_two;
	t_data			*data;
	unsigned int	meals_amount;
	int				end_meals;
}				t_philo;

size_t	getTime(void);

void	check_args(int argc);

int		create_mutexes(t_data *data);

int		create_pthreads_arr(t_data *data);

t_philo	*init_philos(t_data *data);

void	init_data(t_data *data, char *argv[]);

int		start_threads(t_data *data, t_philo *philos);

void	print_status(t_philo *philo, char *status, t_data *data);

void	destroy_mutexes(t_data *data);

void	resting(unsigned int time);

void	*philo_routine(void *philo);

void	free_all(t_data *data, t_philo *philos);

int		ft_atoi(char *str);

#endif
