/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:57:58 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 16:01:37 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *phil, t_data *data)
{
	pthread_mutex_lock(phil->fork_one);
	print_status(phil, TAKE_FORK, data);
	pthread_mutex_lock(phil->fork_two);
	print_status(phil, TAKE_FORK, data);
}

void	give_forks(t_philo *phil)
{
	pthread_mutex_unlock(phil->fork_one);
	pthread_mutex_unlock(phil->fork_two);
}

void	lets_eat(t_philo *phil, t_data *data)
{
	print_status(phil, EAT, data);
	phil->last_meal = getTime() - phil->start;
	resting(data->eat_time);
}

void	lets_sleep(t_philo *phil, t_data *data)
{
	print_status(phil, SLEEP, data);
	resting(data->sleep_time);
}

void	*philo_routine(void *philo)
{
	t_philo	*phil;
	t_data	*data;

	phil = (t_philo *) philo;
	data = phil->data;
	phil->start = getTime();
	phil->last_meal = 0;
	while (1)
	{
		if (data->death_i != -1)
			return (NULL);
		take_forks(phil, data);
		if (data->death_i != -1)
			return (NULL);
		lets_eat(phil, data);
		if (data->death_i != -1)
			return (NULL);
		phil->meals_amount++;
		give_forks(phil);
		lets_sleep(phil, data);
		if (data->death_i != -1)
			return (NULL);
		print_status(phil, THINK, data);
	}
	return (NULL);
}
