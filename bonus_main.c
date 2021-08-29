/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:11:34 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 22:11:50 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "philo_bonus.h"

void	kill_processes(t_bdata *bdata)
{
	int	i;

	i = 0;
	while (i < bdata->num)
	{
		kill(bdata->pids[i], SIGKILL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_bdata	bdata;
	int		i;
	int		*status;

	i = 0;
	status = malloc(sizeof(int));
	check_args(argc);
	init_bdata(&bdata, argv);
	sem_unlink(SEMAPHORE);
	sem_unlink(PRINT);
	init_sem(&bdata);
	start_philos(&bdata);
	if (!argv[5])
	{
		waitpid(-1, 0, 0);
		kill_processes(&bdata);
	}
	else
	{
		while(waitpid(-1, 0, 0) != -1)
			waitpid(-1, 0, 0);
	}
	bend(&bdata);
	return (0);
}
