/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:53:22 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/04 19:56:57 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_to_server(int server_pid, int length, char *send_str)
{
	int	byte_idx;
	int	bit_idx;
	int	bit_check;

	byte_idx = 0;
	while (byte_idx < length)
	{
		bit_idx = 0;
		while (bit_idx < 8)
		{
			bit_check = send_str[byte_idx] >> (7 - bit_idx) & 1;
			if (bit_check == 0)
				kill(server_pid, SIGUSR1);
			else if (bit_check == 1)
				kill(server_pid, SIGUSR2);
			usleep(30);
			bit_idx++;
		}
		usleep(300);
		byte_idx++;
	}
}

void	check_str(int server_pid, char *send_str)
{
	int		length;
	char	*send_with_newline;

	send_with_newline = ft_strjoin(send_str, "\n");
	if (send_with_newline == NULL)
		exit(1);
	length = ft_strlen(send_with_newline);
	send_to_server(server_pid, length, send_with_newline);
	free(send_with_newline);
	exit(0);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	int		fd;

	fd = 1;
	if (argc != 3)
	{
		ft_putstr_fd("./client [SERVER PID] [SEND MESSAGE]\n", fd);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100 || server_pid > 99998)
	{
		ft_putstr_fd("Invalid PID!....\n", fd);
		exit(1);
	}
	check_str(server_pid, argv[2]);
	return (0);
}
