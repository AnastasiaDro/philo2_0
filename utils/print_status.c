/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:36:08 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 15:36:09 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo *philo, char *status, t_data *data)
{	
	pthread_mutex_lock(data->print_m);
	printf("%lu %d %s\n", getTime() - philo->start, philo->index + 1, status);
	pthread_mutex_unlock(data->print_m);
}
