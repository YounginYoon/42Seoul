/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:32:01 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/04 19:28:21 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_user_signal(int sig)
{
	static char	bit_save;
	static int	bit_cnt;

	if (sig == SIGUSR1)
	{
		bit_save |= 0;
		if (bit_cnt < 7)
			bit_save <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		bit_save |= 1;
		if (bit_cnt < 7)
			bit_save <<= 1;
	}
	bit_cnt++;
	if (bit_cnt == 8)
	{
		write(1, &bit_save, 1);
		bit_cnt = 0;
		bit_save = 0;
	}
}

int	main(void)
{
	int	fd;

	fd = 1;
	ft_putstr_fd("pid: ", fd);
	ft_putnbr_fd(getpid(), fd);
	ft_putchar_fd('\n', fd);
	signal(SIGUSR1, get_user_signal);
	signal(SIGUSR2, get_user_signal);
	while (1)
	{
		pause();
	}
}
