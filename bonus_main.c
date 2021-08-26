/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:11:34 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 18:12:11 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_bdata	bdata;
	int		i;

	i = 0;
	check_args(argc);
	init_bdata(&bdata, argv);
	start_philos(&bdata);
	if (!argv[5])
		waitpid(-1, 0, 0);
	else
	{
		while (waitpid(-1, 0, 0) != -1)
			waitpid(-1, 0, 0);
	}
	while (i < bdata.num)
	{
		kill(bdata.pids[i], SIGKILL);
		i++;
	}
	bend(&bdata);
	return (0);
}
