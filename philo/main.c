/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:42:39 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 17:50:00 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philos;

	check_args(argc);
	init_data(&data, argv);
	philos = init_philos(&data);
	start_threads(&data, philos);
	free_all(&data, philos);
	return (0);
}
