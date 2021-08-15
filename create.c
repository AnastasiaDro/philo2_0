#include "philo.h"


int	create_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof (pthread_mutex_t *) * data ->num);
	if (!data->forks)
		return (-1);
	while (i < data->num)
	{
		pthread_mutex_init(data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	create_pthreads_arr(t_data *data)
{
	data->pthreads = malloc(sizeof (pthread_t) * data ->num);
	if (!data->pthreads)
		return (-1);
	return (0);
}

