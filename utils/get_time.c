#include "../philo.h"
#include <sys/time.h>

size_t getTime()
{
	size_t milisec;
	struct timeval t;

	gettimeofday(&t, NULL);
	milisec = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (milisec);
}
