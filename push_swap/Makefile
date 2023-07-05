# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 14:27:25 by youyoon           #+#    #+#              #
#    Updated: 2023/07/05 19:32:26 by youyoon          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = stack_push.c\
	stack_pop.c\
	push_swap.c\
	utils.c\
	utils2.c\
	validate_arg.c\
	operations_push.c\
	operations_swap.c\
	operations_rotate.c\
	operations_rotate2.c\
	sort.c\
	sort_rotate.c\
	sort_find_location.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ libft/libft.a

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
