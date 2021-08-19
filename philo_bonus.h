//
// Created by Cesar Erebus on 8/19/21.
//

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#define SEMAPHORE	"SEMA"
#define DIED		"DIED"
#define IS_FULL		"IS_FULL"

#include <semaphore.h>
#include "philo.h"
typedef struct s_bdata
{
	long int		num;
	long int		die_time;
	long int		eat_time;
	long int		sleep_time;
	long int		meals_n;
	int				death_i;
	char 			*sem_name;
	char			*death_name;
	int				is_food_limited;
	int				is_ready;
	sem_t			*sem;
	sem_t			*die_sem;
	sem_t			*eat_full_sem;
}				t_bdata;

typedef struct s_bphilo
{
	int				index;
	size_t			last_meal;
	size_t			start;
	unsigned int	meals_amount;
	int				end_meals;
}				t_bphilo;

int	check_bdata(t_bdata *data, char *argv[]);
void	init_bdata(t_bdata *data, char *argv[]);
void init_sem(t_bdata *bdata);
void init_die_sem(t_bdata *bdata);
void be_alive(t_bdata *bdata, int i);
#endif
