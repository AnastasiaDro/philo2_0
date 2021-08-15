#include "philo.h"


void *philo_routine(void *philo)
{
	t_philo *phil;
	t_data 	*data;

	phil = (t_philo *) philo;
	data = phil->data;
	phil->last_meal = getTime();
	phil->start = phil->last_meal;
	pthread_mutex_lock(data->dead_m);

	pthread_mutex_unlock(data->dead_m);
	while(1)
	{
		if (data->death_i != -1)
			return (NULL);
		pthread_mutex_lock(phil->fork_one);
		print_status(phil, TAKE_FORK, data);
		pthread_mutex_lock(phil->fork_two);
		print_status(phil, TAKE_FORK, data);
		print_status(phil, EAT, data);
		phil->last_meal = getTime() - phil->start;
		usleep(data->eat_time * 1000);
		pthread_mutex_unlock(phil->fork_one);
		pthread_mutex_unlock(phil->fork_two);
		print_status(phil, SLEEP, data);
		usleep(data->sleep_time * 1000);
		print_status(phil, THINK, data);
	}
	return (NULL);
}

void	*death_eye(void *phil)
{
	int		i;
	size_t	t;
	t_data	*data;
	t_philo *philos;

	philos = (t_philo *) phil;
	data = philos->data;
	while(data->death_i == -1)
	{
		i = 0;
		while (i < data->num)
		{
			t = getTime() - philos[i].start;
//			printf("here\n");
//			printf("index = %d\n", philos[i].index);
//			printf("t = %lu\nlast.meal = %lu\n", t, philos[i].last_meal);
//			printf("diff = %lu\n", t - philos[i].last_meal);
			if (getTime() - philos->start - philos[i].last_meal > (size_t) data->die_time)
			{
				pthread_mutex_lock(data->dead_m);
				data->death_i = i;
				print_status(&philos[i], DIED, data);
				break;
			}
			i++;
		}
	}
	return (NULL);
}

int	start_threads(t_philo *philos, t_data *data)
{
	int i;
	pthread_t death_checker;

	i = 0;
	pthread_create(&death_checker, NULL, &death_eye, philos);
	while (i < data->num)
	{
		if (pthread_create(&data->pthreads[i], NULL, &philo_routine, &philos[i]) != 0) {
			perror("Failed to create thread\n");
			return (i);
		}
		usleep(100);
		i++;
	}
	return (0);
}


void	exec(t_data *data, t_philo *philos)
{
	start_threads(philos, data);
	destroy_mutexes(data);
}