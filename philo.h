#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"
#include <pthread.h>
#define TAKE_FORK "has taken a fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DIED "died"


typedef struct s_data
{
	unsigned int	num;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	int 			meals_n;
	int 			dead_i;
	pthread_t 		*phreads;
	pthread_mutex_t **forks;
	pthread_mutex_t *dead_m;
	pthread_mutex_t *print_m;
}				t_data;

typedef struct s_philo
{

}				t_philo;

size_t	getTime();

void	check_args(int argc);

void	check_args(int argc);
#endif
