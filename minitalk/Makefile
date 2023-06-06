# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 17:16:00 by youyoon           #+#    #+#              #
#    Updated: 2023/06/06 17:24:50 by youyoon          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LDFLAGS = -fsanitize=address
LDLIBS = -Llibft -lft

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(SERVER): server.o $(LIBFT)
	$(CC) -o $@ $< $(LDLIBS) $(LDFLAGS)

$(CLIENT): client.o $(LIBFT)
	$(CC) -o $@ $< $(LDLIBS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(LIBFT)

re: fclean all

.PHONY: all libft clean fclean re
