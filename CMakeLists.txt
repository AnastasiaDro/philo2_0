cmake_minimum_required(VERSION 3.20)
project(philo2_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(philo2_0 main.c utils/get_time.c utils/ft_atoi.c utils/resting.c check_args.c init.c create.c exec1.c
                print_status.c destroy_mutexes.c free_all.c philo_routine.c )

#add_executable(philo2_0 sem1.c)

#add_executable(philo2_0 bonus_main.c bonus_init.c bstart_philos.c bonus_be_alive.c bonus_print_status.c
#        utils/get_time.c utils/ft_atoi.c check_args.c utils/resting.c bend.c bonus_life_funcs.c)