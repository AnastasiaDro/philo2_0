//
// Created by Cesar Erebus on 8/19/21.
//

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#define SEMAPHORE	"SEMA"
#define IS_FULL		"IS_FULL"
#define PRINT		"PRINT"

#include <semaphore.h>
#include "philo.h"
#include <wait.h>
typedef struct s_bdata
{
	long int		num;
	size_t 			die_time;
	size_t 			eat_time;
	size_t 		sleep_time;
	long int		meals_n;
	int				death_i;
	char 			*sem_name;
	char			*death_name;
	int				is_food_limited;
	int				is_ready;
	sem_t			*sem;
	sem_t			*die_sem;
	sem_t			*eat_full_sem;
	sem_t			*print_sem;
	long int 		stat_time;
	int 			is_dead;
}				t_bdata;

typedef struct s_bphilo
{
	int				index;
	size_t			last_meal;
	size_t			start;
	unsigned int	meals_amount;
	int				end_meals;
	sem_t			*sem;
	sem_t			*die_sem;
	sem_t			*eat_full_sem;
	t_bdata 		*bdata;

}				t_bphilo;

int		check_bdata(t_bdata *data, char *argv[]);
void	init_bdata(t_bdata *data, char *argv[]);
void	be_alive(t_bdata *bdata, int i);
void	b_print_status(t_bphilo *bphilo, char *status, t_bdata *bdata);
void 	init_sem(t_bdata *bdata);
void	start_philos(t_bdata *bdata);
#endif
