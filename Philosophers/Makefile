# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 15:18:34 by youyoon           #+#    #+#              #
#    Updated: 2023/07/27 17:09:37 by youyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo
CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra
THREAD 	= -pthread
RM 		= rm -rf

SRCS = philo/init.c	\
		philo/main.c\
		philo/philo.c\
		philo/utils.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREAD) $(SRCS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re