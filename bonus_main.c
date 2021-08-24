
#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_bdata	bdata;

	check_args(argc);
	init_bdata(&bdata, argv);

	start_philos(&bdata);
	waitpid(-1, NULL, 0);

	return (0);
}
