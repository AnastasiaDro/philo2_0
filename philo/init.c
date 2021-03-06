/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:39:11 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 15:40:57 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_data(t_data *data, char *argv[])
{
	if (data->num == -1 || data->die_time == -1 || \
		data->eat_time == -1 || data->sleep_time == -1 || \
			(argv[5] && data->meals_n == -1))
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}

void	init_data(t_data *data, char *argv[])
{
	data->num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->meals_n = ft_atoi(argv[5]);
		data->is_food_limited = 1;
		data->is_ready = 0;
	}
	else
		data->is_food_limited = 0;
	if (check_data(data, argv))
		exit(1);
	data->death_i = -1;
	create_mutexes(data);
	create_pthreads_arr(data);
}

pthread_mutex_t	*get_first(int i, t_data *data)
{
	pthread_mutex_t	*first_fork;

	if (i == 0)
		first_fork = data->forks[data->num - 1];
	else
		first_fork = data->forks[i - 1];
	return (first_fork);
}

t_philo	*init_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = malloc(data->num * sizeof (t_philo));
	if (!philos)
		return (NULL);
	while (++i < data->num)
	{
		philos[i].index = i;
		if ((i + 1) % 2)
		{
			philos[i].fork_one = get_first(i, data);
			philos[i]. fork_two = data->forks[i];
		}
		else
		{
			philos[i].fork_one = data->forks[i - 1];
			philos[i]. fork_two = data->forks[i];
		}
		philos[i].data = data;
		philos[i].meals_amount = 0;
		philos[i].end_meals = 0;
	}
	return (philos);
}
