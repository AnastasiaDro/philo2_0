#include "../philo.h"

void	print_status(t_philo *philo, char *status, t_data *data)
{
	if (!data->printed_death)
	{
		pthread_mutex_lock(data->print_m);
		printf("%lu %d %s\n", getTime() - philo->start, philo->index + 1, status);
		pthread_mutex_unlock(data->print_m);
	}
}
