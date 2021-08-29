/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:42:52 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 15:43:03 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	unsigned int	i;

	i = 0;
	free(data->dead_m);
	free(data->print_m);
	while (i < data->num)
	{
		free(data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data->pthreads);
}

void	free_all(t_data *data, t_philo *philos)
{
	destroy_mutexes(data);
	free_data(data);
	free(philos);
}
