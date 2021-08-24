//
// Created by Cesar Erebus on 8/19/21.
//

#include "philo_bonus.h"
void	start_philos(t_bdata *bdata)
{
	int i;
	int pid;
	int flag;

	i = 0;
	flag = 0;
	sem_unlink(SEMAPHORE);
	sem_unlink(DIED);
	sem_unlink(IS_FULL);
	sem_unlink(PRINT);
	while (i < bdata->num)
	{
		pid = fork();
		if (pid > 0)
		{
			i++;
			if (flag == 0)
			{
				init_sem(bdata);
				flag = 1;
			}
		}
		usleep(50);
		if (pid == 0)
			be_alive(bdata, i);
	}
}
