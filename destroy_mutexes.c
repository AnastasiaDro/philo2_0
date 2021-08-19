/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:18:12 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 16:18:14 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(data->print_m);
	pthread_mutex_destroy(data->dead_m);
	while (i < data->num)
	{
		pthread_mutex_destroy(data->forks[i]);
		i++;
	}
}
