//
// Created by Cesar Erebus on 8/19/21.
//
#include "philo_bonus.h"

void	*philo_routine(t_bdata *bdata, int i)
{
	t_philo	phil;


	t_data	*data;

	phil = (t_philo *) philo;
	data = phil->data;
	phil->start = getTime();
	phil->last_meal = 0;
	while (1)
	{
		if (data->death_i != -1)
			return (NULL);
		take_forks(phil, data);
		if (data->death_i != -1)
			return (NULL);
		lets_eat(phil, data);
		if (data->death_i != -1)
			return (NULL);
		phil->meals_amount++;
		give_forks(phil);
		lets_sleep(phil, data);
		if (data->death_i != -1)
			return (NULL);
		print_status(phil, THINK, data);
	}
	return (NULL);
}