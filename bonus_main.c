
#include <libc.h>
#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_bdata	bdata;
	int 	i;

	i = 0;
	check_args(argc);
	init_bdata(&bdata, argv);
	start_philos(&bdata);
	waitpid(-1, 0, 0);
	while (i < bdata.num)
	{
		kill(bdata.pids[i], SIGKILL);
		i++;
	}
	bend(&bdata);
	return (0);
}
