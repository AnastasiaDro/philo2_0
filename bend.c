//
// Created by Cesar Erebus on 8/24/21.
//
#include "philo_bonus.h"

int	bend(t_bdata *bdata)
{
	free(bdata->pids);
	sem_unlink(SEMAPHORE);
	sem_unlink(PRINT);
	return (0);
}
