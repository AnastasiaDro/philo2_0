/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstart_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:02:34 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 18:11:21 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "philo_bonus.h"
void	start_philos(t_bdata *bdata)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	sem_unlink(SEMAPHORE);
	sem_unlink(DIED);
	sem_unlink(IS_FULL);
	sem_unlink(PRINT);
	while (++i < bdata->num)
	{
		bdata->pids[i] = fork();
		if (bdata->pids[i] > 0)
		{
			if (flag == 0)
			{
				init_sem(bdata);
				flag = 1;
			}
			usleep(50);
			continue ;
		}
		if (bdata->pids[i] == 0)
			be_alive(bdata, i);
	}
}
