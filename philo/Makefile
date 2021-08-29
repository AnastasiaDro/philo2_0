# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 18:02:22 by cerebus           #+#    #+#              #
#    Updated: 2021/08/29 18:07:16 by cerebus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEAD = philo.h

UTILS = utils/ft_atoi.c utils/get_time.c utils/resting.c

SRCS = main.c check_args.c init.c create.c exec1.c \
       destroy_mutexes.c free_all.c philo_routine.c \
      print_status.c

OBJS = $(SRCS:.c=.o)

UOBJS = $(UTILS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(UOBJS) $(HEAD)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(UOBJS)

clean:
			@$(RM) $(OBJS) $(UOBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: 	all run clean fclean re