//
// Created by Cesar Erebus on 8/19/21.
//
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <fcntl.h>
#include <errno.h>

#define THREAD_NUM 4

sem_t *semaphore;

void	*routine(void *args)
{
	sem_wait(semaphore);
	sleep(1);
	printf("Hello from thread %d\n", *(int*)args);
	sem_post(semaphore);
	free(args);
	return NULL;
}

int main()
{
	pthread_t th[THREAD_NUM];
	int i;

	char name[] = "SEMA";
	sem_unlink("SEMAPHORE");
	semaphore = sem_open(name, O_CREAT, 0644, 1);
	for(i = 0; i < THREAD_NUM; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		
		if(pthread_create(&th[i], NULL, &routine, a) != 0)
		{
			exit(1);
		}
	//	sleep(1);
	}
	for(i = 0; i < THREAD_NUM; i++)
	{
		if(pthread_join(th[i], NULL) != 0)
		{
			exit(1);
		}
	}
	sem_close(semaphore);
	sem_unlink("SEMAPHORE");
	return (0);
}