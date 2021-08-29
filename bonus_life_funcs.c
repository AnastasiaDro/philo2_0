/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_life_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:15:11 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 21:42:15 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_bphilo *bphil, t_bdata *bdata)
{
	sem_wait(bdata->sem);
	b_print_status(bphil, TAKE_FORK, bdata);
	sem_wait(bdata->sem);
	b_print_status(bphil, TAKE_FORK, bdata);
}

void	give_forks(t_bdata *bdata)
{
	sem_post(bdata->sem);
	sem_post(bdata->sem);
}

void	lets_eat(t_bphilo *bphil, t_bdata *bdata)
{	
	bphil->last_meal = getTime();
	b_print_status(bphil, EAT, bdata);
	bphil->meals_amount++;
	resting(bdata->eat_time);
}

void	lets_sleep(t_bphilo *bphil, t_bdata *bdata)
{
	b_print_status(bphil, SLEEP, bdata);
	resting(bdata->sleep_time);
}
