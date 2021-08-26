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
	size_t	a;

	a = -1;
	if (data->num == a || data->die_time == a || \
	data->eat_time == a || data->sleep_time == a || \
	(argv[5] && data->meals_n == a))
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}

void 	init_sem(t_bdata *bdata)
{
	bdata->sem = sem_open(SEMAPHORE, O_CREAT, 0644, bdata->num);
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
	}
	else
		data->is_food_limited = 0;
	if (check_bdata(data, argv))
		exit (1);
	data->pids = malloc(sizeof (int) * (data->num));
	if (!data->pids)
		exit (1);
}
