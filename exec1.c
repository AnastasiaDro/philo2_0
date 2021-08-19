/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:43:19 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 16:17:27 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	resting(unsigned int time)
{
	unsigned long	start;

	start = getTime();
	while (getTime() - start < (unsigned long)time)
		usleep(100);
}

int	are_philos_full(t_philo *philo, t_data *data)
{
	if (philo->meals_amount == data->meals_n && !philo->end_meals)
	{
		data->is_ready++;
		philo->end_meals = 1;
		if (data->is_ready == data->num)
		{
			pthread_mutex_lock(data->dead_m);
			data->death_i = philo->index;
			pthread_mutex_unlock(data->dead_m);
			return (1);
		}
	}
	return (0);
}

void	*death_eye(void *philo)
{
	int		i;
	t_data	*data;
	t_philo	*phil;

	phil = (t_philo *) philo;
	data = phil->data;
	while (data->death_i == -1)
	{
		i = -1;
		while (++i < data->num)
		{
			if (getTime() - phil->start - phil[i].last_meal \
					 > (size_t) data->die_time)
			{
				pthread_mutex_lock(data->dead_m);
				data->death_i = i;
				pthread_mutex_unlock(data->dead_m);
				print_status(&phil[i], DIED, data);
				return (NULL);
			}
			if (are_philos_full(&phil[i], data))
				return (NULL);
		}
	}
	return (NULL);
}

int	start_threads(t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	death_checker;

	i = 0;
	while (i < data->num)
	{
		if (pthread_create(&data->pthreads[i], NULL, \
			&philo_routine, &philos[i]) != 0)
		{
			perror("Failed to create thread\n");
			return (i);
		}
		pthread_detach(data->pthreads[i]);
		usleep(100);
		i++;
	}
	pthread_create(&death_checker, NULL, &death_eye, philos);
	pthread_join(death_checker, NULL);
	return (0);
}
