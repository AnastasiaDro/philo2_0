//
// Created by Cesar Erebus on 8/19/21.
//
#include <sys/errno.h>
#include "philo_bonus.h"


//void	init_sem_inside(t_bphilo *phil, t_bdata *bdata)
//{
//	phil->sem = sem_open(SEMAPHORE, O_CREAT, 0644, bdata->num);
//	phil->die_sem = sem_open(DIED, O_CREAT, 0644, 1);
//	phil->eat_full_sem = sem_open(IS_FULL, O_CREAT, 0644, bdata->num);
//}

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
	b_print_status(bphil, EAT, bdata);
	bphil->last_meal = getTime() - bphil->start;
	resting(bdata->eat_time);
}

void	lets_sleep(t_bphilo *bphil, t_bdata *bdata)
{
	b_print_status(bphil, SLEEP, bdata);
	resting(bdata->sleep_time);
}

int		check_death(t_bphilo *bphil, t_bdata *bdata)
{
	int is;

	is = EEXIST;
	if (sem_open("DIED", O_EXCL) == &is)
		exit(0);
	if (getTime() - bphil->start - bphil->last_meal \
		> (size_t) bdata->die_time)
	{
		sem_open("DIED", O_CREAT, 0644, 1);
		b_print_status(bphil, DIED, bdata);
		exit(0);
	}
//	if (are_philos_full(&phil[i], data))
//		return (NULL);
	return (0);
}

void	be_alive(t_bdata *bdata, int i)
{
	t_bphilo	bphil;

	bphil.start = getTime();
	bphil.last_meal = 0;
	bphil.index	= i;
	bphil.end_meals = 0;
	init_sem(bdata);
	while (1)
	{
		check_death(&bphil, bdata);
		take_forks(&bphil, bdata);
		lets_eat(&bphil, bdata);
		give_forks(bdata);
		check_death(&bphil, bdata);
		bphil.meals_amount++;
		if (bphil.meals_amount == bdata->num && !(bphil.end_meals))
		{
			sem_wait(bphil.eat_full_sem);
			bphil.end_meals = 1;
		}
		lets_sleep(&bphil, bdata);
		check_death(&bphil, bdata);
		b_print_status(&bphil, THINK, bdata);
	}
	exit(1);
}