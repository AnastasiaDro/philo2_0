//
// Created by Cesar Erebus on 8/19/21.
//

#include <signal.h>
#include "philo_bonus.h"
void	start_philos(t_bdata *bdata)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	sem_unlink(SEMAPHORE);
	sem_unlink(DIED);
	sem_unlink(IS_FULL);
	sem_unlink(PRINT);
	while (i < bdata->num)
	{
		bdata->pids[i] = fork();
		if (bdata->pids[i] > 0)
		{
			i++;
			if (flag == 0)
			{
				init_sem(bdata);
				flag = 1;
			}
			usleep(50);
			continue;
		}
		if (bdata->pids[i] == 0)
			be_alive(bdata, i);
	}

}
