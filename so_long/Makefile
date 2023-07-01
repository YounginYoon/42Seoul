# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 15:59:58 by youyoon           #+#    #+#              #
#    Updated: 2023/07/01 12:33:24 by youyoon          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRC = src/check_valid.c	\
		src/dfs.c		\
		src/error.c		\
		src/free_memory.c\
		src/init.c		\
		src/make_map.c	\
		src/run_window.c\
		src/so_long_utils.c\
		src/so_long.c	\
		src/update_utils.c\
		src/update.c	\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./ft_printf
	make -C ./libft
	make -C ./mlx
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRC) -o $@ ft_printf/libftprintf.a libft/libft.a

clean:
	make clean -C ./ft_printf
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make clean -C ./mlx
	make fclean -C ./ft_printf
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
