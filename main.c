#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philos;

	check_args(argc);
	init_data(&data, argv);
	philos = init_philos(&data);
	exec(&data, philos);
	free_all(&data, philos);
	return 0;
}
