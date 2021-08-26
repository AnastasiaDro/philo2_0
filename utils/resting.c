
#include "../philo.h"

void	resting(unsigned int time)
{
	unsigned long	start;

	start = getTime();
	while (getTime() - start < (unsigned long)time)
		usleep(100);
}
