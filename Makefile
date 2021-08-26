NAME = philo

UTILS = utils/ft_atoi.c utils/get_time.c utils/resting.c

SRCS = main.c check_args.c init.c create.c exec1.c \
       destroy_mutexes.c free_all.c philo_routine.c \
      print_status.c


BONUS = bend.c bonus_be_alive.c \
		bonus_init.c bonus_main.c bonus_print_status.c bstart_philos.c \
		check_args.c


OBJS = $(SRCS:.c=.o)

BOBJS = $(BONUS:.c=.o)

UOBJS = $(UTILS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(UOBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(UOBJS)

run:		$(NAME)
			@./$(NAME)

clean:
			@$(RM) $(OBJS) $(UOBJS)

fclean:		clean
			@$(RM) $(NAME)

bonus:		$(BOBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(UOBJS)

re:			fclean all

.PHONY: 	all run clean fclean re