NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g
SRCS = srcs/free_mem.c\
	srcs/init.c\
	srcs/main.c\
	srcs/monitor.c\
	srcs/print.c\
	srcs/routine_one.c\
	srcs/routine.c\
	srcs/utils.c\

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re