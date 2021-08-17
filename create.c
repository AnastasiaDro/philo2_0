#include "philo.h"


int	create_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->dead_m = malloc(sizeof (pthread_mutex_t));
	pthread_mutex_init(data->dead_m, NULL);
	data->print_m = malloc(sizeof (pthread_mutex_t));
	pthread_mutex_init(data->print_m, NULL);
	data->start_m = malloc(sizeof (pthread_mutex_t));
	pthread_mutex_init(data->start_m, NULL);
	data->prnt_dth_m = malloc(sizeof (pthread_mutex_t));
	pthread_mutex_init(data->prnt_dth_m, NULL);
	data->forks = malloc(sizeof (pthread_mutex_t *) * data ->num);
	while (i < data->num)
	{
		data->forks[i] = malloc(sizeof(pthread_mutex_t));
		if(data->forks[i])
			pthread_mutex_init(data->forks[i], NULL);
		else
			return (-1);
		i++;
	}
	if (!data->forks)
		return (-1);
	return (0);
}

int	create_pthreads_arr(t_data *data)
{
	data->pthreads = malloc(sizeof (pthread_t) * data ->num);
	if (!data->pthreads)
		return (-1);
	return (0);
}


