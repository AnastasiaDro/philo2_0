
#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_bdata	bdata;

	check_args(argc);
	init_bdata(&bdata, argv);
	init_sem(&bdata);
	init_die_sem(&bdata);
	//


	return (0);
}
