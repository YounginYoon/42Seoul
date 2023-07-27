/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:32:36 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/27 17:12:40 by youyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	while (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] && i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (!us1[i] && i < n)
		return (us1[i] - us2[i]);
	return (0);
}

long long	get_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (-1);
	return ((mytime.tv_sec * 1000) + (mytime.tv_usec / 1000));
}

void	sleep_until_even_eat(t_arg *arg)
{
	struct timeval	start_time;
	struct timeval	current_time;
	int				time_wasted;

	gettimeofday(&start_time, NULL);
	while (1)
	{
		gettimeofday(&current_time, NULL);
		time_wasted = (current_time.tv_usec - start_time.tv_usec) + \
					(current_time.tv_sec - start_time.tv_sec) * 1000000;
		if (time_wasted > arg->time_to_eat * 900)
			break ;
		usleep(arg->time_to_eat);
	}
}

void	spend_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = get_time();
	while (!(arg->finish))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}
