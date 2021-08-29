/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_be_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:02:29 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/29 15:10:59 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "philo_bonus.h"

void	*check_death(void *bphilo)
{
	size_t		time;
	t_bphilo	*bphil;
	t_bdata		*bdata;

	bphil = (t_bphilo *)bphilo;
	bdata = bphil->bdata;
	while (1)
	{
		time = getTime() - bphil->last_meal;
		if ((int) time < 0)
			time = time * (-1);
		if (time > bdata->die_time)
		{
			sem_wait(bdata->print_sem);
			printf("%lu %d %s\n", getTime() - bphil->start, \
				bphil->index + 1, DIED);
			free(bdata->pids);
			exit (1);
		}
		if (bdata->is_food_limited && bphil->meals_amount == bdata->meals_n)
		{
			bdata->is_full = 1;
			return (0);
		}
	}
}

void	be_alive(t_bdata *bdata, int i)
{
	t_bphilo	bphil;
	pthread_t	death_checker;

	bphil.start = getTime();
	bphil.last_meal = getTime();
	bphil.index = i;
	bphil.bdata = bdata;
	bphil.meals_amount = 0;
	pthread_create(&death_checker, NULL, &check_death, (void *)(&bphil));
	pthread_detach(death_checker);
	while (!bdata->is_full)
	{
		take_forks(&bphil, bdata);
		lets_eat(&bphil, bdata);
		give_forks(bdata);
		lets_sleep(&bphil, bdata);
		b_print_status(&bphil, THINK, bdata);
	}
	free(bdata->pids);
	exit (0);
}
