#include "philo.h"

void	resting(unsigned int time)
{
	unsigned long	start;

	start = getTime();
	while (getTime() - start < (unsigned long)time)
		usleep(100);
}

void	say_dead(t_data *data, t_philo *phil)
{
	pthread_mutex_lock(data->prnt_dth_m);
	print_status(phil, DIED, data);
	data->printed_death = 1;
	pthread_mutex_unlock(data->prnt_dth_m);
}

void	*philo_routine(void *philo)
{
	t_philo	*phil;
	t_data	*data;

	phil = (t_philo *) philo;
	data = phil->data;
	phil->start = getTime();
	phil->last_meal = phil->start;
	while (1)
	{
		if (data->death_i != -1 )
		{
			if (!data->is_food_limited && data->death_i == phil->index)
				say_dead(data, phil);
			return (NULL);
		}
		pthread_mutex_lock(phil->fork_one);
		print_status(phil, TAKE_FORK, data);
		pthread_mutex_lock(phil->fork_two);
		print_status(phil, TAKE_FORK, data);
		print_status(phil, EAT, data);
		phil->last_meal = getTime() - phil->start;
		resting(data->eat_time);
		pthread_mutex_unlock(phil->fork_one);
		pthread_mutex_unlock(phil->fork_two);
		phil->meals_amount++;
		print_status(phil, SLEEP, data);
		resting(data->sleep_time);
		if (data->death_i == -1)
			print_status(phil, THINK, data);
	}
	return (NULL);
}

void	*death_eye(void *phil)
{
	int		i;
	t_data	*data;
	t_philo *philos;

	philos = (t_philo *) phil;
	data = philos->data;
	while (data->death_i == -1)
	{
		i = -1;
		while (++i < data->num)
		{
			if (getTime() - philos->start - philos[i].last_meal > (size_t) data->die_time)
			{
				pthread_mutex_lock(data->dead_m);
				data->death_i = i;
				pthread_mutex_unlock(data->dead_m);
				if (data->num == 1)
					print_status(&philos[0], DIED, data);
				return (NULL);
			}
			if (philos[i].meals_amount == data->meals_n)
			{
				data->is_ready++;
				if (data->is_ready == data->num)
				{
					pthread_mutex_lock(data->dead_m);
					data->death_i = i;
					pthread_mutex_unlock(data->dead_m);
					return (NULL);
				}
			}
		}
	}
	return (NULL);
}

int	start_threads(t_philo *philos, t_data *data)
{
	int			i;
	pthread_t	death_checker;

	i = 0;

	while (i < data->num)
	{
		if (pthread_create(&data->pthreads[i], NULL, &philo_routine, &philos[i]) != 0) {
			perror("Failed to create thread\n");
			return (i);
		}
		usleep(100);
		i++;
	}
	pthread_create(&death_checker, NULL, &death_eye, philos);
	pthread_join(death_checker, NULL);
	return (0);
}

void	exec(t_data *data, t_philo *philos)
{
	int i;

	i = 0;
	start_threads(philos, data);
	if (data->num == 1)
	{
		pthread_detach(data->pthreads[i]);
	}
	else
	{
		while(i < data->num)
		{
			pthread_join(data->pthreads[i], NULL);
			i++;
		}
	}
	destroy_mutexes(data);
}
