
#include <signal.h>
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

void	*check_death(void *bphilo)
{
	size_t time;
	t_bphilo *bphil = (t_bphilo *)bphilo;
	t_bdata *bdata = bphil->bdata;
	while(1)
	{
		time = getTime() - bphil->last_meal;
		if ((int) time < 0)
			time = time * (-1);
		if (time > bdata->die_time)
		{
			sem_wait(bdata->print_sem);
			printf("%lu %d %s\n", getTime() - bphil->start, bphil->index + 1, DIED);
			exit(0);
		}
		if (bdata->is_food_limited && bphil->meals_amount == bdata->meals_n)
		{
			bdata->is_dead = 1;
			sem_wait(bdata->print_sem);
			return NULL;
		}
	}
}

void	be_alive(t_bdata *bdata, int i)
{
	t_bphilo	bphil;

	bphil.start = getTime();
	bphil.last_meal = getTime();
	bphil.index = i;
	bphil.bdata = bdata;
	init_sem(bdata);

	pthread_t death_checker;
	pthread_create(&death_checker, NULL, &check_death, (void *)(&bphil));
	pthread_detach(death_checker);
	while (1)
	{
		take_forks(&bphil, bdata);
//		if (bdata->is_dead)
//			exit(0);
		lets_eat(&bphil, bdata);
		give_forks(bdata);
//		if (bdata->is_dead)
//			exit(0);
		lets_sleep(&bphil, bdata);
//		if (bdata->is_dead)
//			exit(0);
		b_print_status(&bphil, THINK, bdata);
	}
}
