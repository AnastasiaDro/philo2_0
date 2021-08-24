//
// Created by Cesar Erebus on 8/19/21.
//

//
// Created by Cesar Erebus on 8/19/21.
//
#include "philo_bonus.h"
#include "philo.h"

int	check_bdata(t_bdata *data, char *argv[])
{
	if (data->num == -1 || data->die_time == -1 || \
	data->eat_time == -1 || data->sleep_time == -1 || \
	(argv[5] && data->meals_n == -1))
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}

void 	init_sem(t_bdata *bdata)
{
	bdata->sem = sem_open(SEMAPHORE, O_CREAT, 0644, bdata->num);
	bdata->die_sem = sem_open(DIED, O_CREAT, 0644, 1);
	bdata->eat_full_sem = sem_open(IS_FULL, O_CREAT, 0644, bdata->num);
	bdata->print_sem = sem_open(PRINT, O_CREAT, 0644, bdata->num);
}


void	init_bdata(t_bdata *data, char *argv[])
{
	data->num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->is_dead = 0;
	if (argv[5])
	{
		data->meals_n = ft_atoi(argv[5]);
		data->is_food_limited = 1;
		data->is_ready = 0;
	}
	else
		data->is_food_limited = 0;
	if (check_bdata(data, argv))
		exit(1);
}
