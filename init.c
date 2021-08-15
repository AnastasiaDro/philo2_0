
#include "philo.h"

int	check_data(t_data *data, char *argv[])
{
	if (data->num == -1 || data->die_time == -1 || data->eat_time == -1 || data->sleep_time == -1)
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}

void	init_data(t_data *data, char *argv[])
{
	data->num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		data->meals_n = ft_atoi(argv[5]);
	if (check_data(data, argv))
		exit(1);



	data->dead_i = -1;

}