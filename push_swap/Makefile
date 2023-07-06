# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 14:27:25 by youyoon           #+#    #+#              #
#    Updated: 2023/07/06 16:07:49 by youyoon          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = mandatory/operations_push.c\
	mandatory/operations_rotate.c\
	mandatory/operations_rotate2.c\
	mandatory/operations_swap.c\
	mandatory/push_swap.c\
	mandatory/sort_find_location.c\
	mandatory/sort_rotate.c\
	mandatory/sort.c\
	mandatory/stack_pop.c\
	mandatory/stack_push.c\
	mandatory/utils.c\
	mandatory/utils2.c\
	mandatory/validate_arg.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(SRCS) -o $@ libft/libft.a

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
