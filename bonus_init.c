/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:02:12 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/29 14:56:11 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "philo.h"

int	check_bdata(t_bdata *data, char *argv[])
{
	size_t	a;

	a = -1;
	if (data->num == (long int) a || data->die_time == a || \
	data->eat_time == a || data->sleep_time == a || \
	(argv[5] && data->meals_n == a))
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}

void	init_sem(t_bdata *bdata)
{
	bdata->sem = sem_open(SEMAPHORE, O_CREAT, 0644, bdata->num);
	bdata->print_sem = sem_open(PRINT, O_CREAT, 0644, 1);
}

void	init_bdata(t_bdata *data, char *argv[])
{
	data->num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->is_full = 0;
	if (argv[5])
	{
		data->meals_n = ft_atoi(argv[5]);
		data->is_food_limited = 1;
	}
	else
	{
		data->is_food_limited = 0;
		data->meals_n = 1;
	}	
	if (check_bdata(data, argv))
		exit (1);
	data->pids = malloc(sizeof (int) * (data->num));
	if (!data->pids)
		exit (1);
}
