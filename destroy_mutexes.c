#include "philo.h"

void destroy_mutexes(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_destroy(data->print_m);
	pthread_mutex_destroy(data->dead_m);
	pthread_mutex_destroy(data->prnt_dth_m);
	while (i < data->num)
	{
		pthread_mutex_destroy(data->forks[i]);
		i++;
	}
}