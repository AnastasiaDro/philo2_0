/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstart_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:02:34 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/29 14:55:19 by cerebus          ###   ########.fr       */
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
	while (++i < bdata->num)
	{
		bdata->pids[i] = fork();
		if (bdata->pids[i] > 0)
		{
			usleep(50);
			continue ;
		}
		if (bdata->pids[i] == 0)
			be_alive(bdata, i);
	}
}
