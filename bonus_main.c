
#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_bdata	bdata;

	check_args(argc);
	init_bdata(&bdata, argv);

	start_philos(&bdata);
//	while(waitpid(-1, NULL, 0) != -1)
//	{
//		waitpid(-1, NULL, 0);
//	}
	while(wait(NULL) != -1)
		wait(NULL);
	return (0);
}
