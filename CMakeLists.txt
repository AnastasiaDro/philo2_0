cmake_minimum_required(VERSION 3.20)
project(philo2_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(philo2_0 main.c utils/get_time.c utils/ft_atoi.c check_args.c init.c create.c exec1.c
                utils/print_status.c destroy_mutexes.c free_all.c philo_routine.c)
