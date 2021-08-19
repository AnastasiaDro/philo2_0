//
// Created by Cesar Erebus on 8/19/21.
//
#include "philo_bonus.h"

void	b_print_status(t_bphilo *bphilo, char *status, t_bdata *bdata)
{
	sem_wait(bdata->print_sem);
	printf("%lu %d %s\n", getTime() - bphilo->start, bphilo->index + 1, status);
	sem_post(bdata->print_sem);
}
