//
// Created by Cesar Erebus on 8/19/21.
//

#include "philo_bonus.h"
void	start_philos(t_bdata *bdata)
{
	int i;
	int pid;

	i = 0;
	while (i < bdata->num)
	{
		pid = fork();
		if (pid == 0)
		{
			be_alive(bdata, i);
		}
		else
			i++;
	}
}