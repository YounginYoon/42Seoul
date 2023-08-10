/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:20:08 by youyoon           #+#    #+#             */
/*   Updated: 2023/08/10 13:20:08 by youyoon          ###   ########.fr       */
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

void	swap_fork(t_philo *philo)
{
	int	temp;

	temp = philo->fork_left;
	philo->fork_left = philo->fork_right;
	philo->fork_right = temp;
}

long	calculate_timeval(struct timeval *start, struct timeval *end)
{
	long	diff_time;

	diff_time = (end->tv_sec - start->tv_sec) * 1e3 + \
				(end->tv_usec - start->tv_usec) / 1e3;
	return (diff_time);
}

void	sleep_unit(t_monitor *monitor, long aim_time, \
						struct timeval start_time, long unit)
{
	struct timeval	curr_time;

	while (1)
	{
		if (gettimeofday(&(curr_time), NULL) != 0)
		{
			monitor->finish_flag = 2;
			return ;
		}
		if (calculate_timeval(&(start_time), &(curr_time)) >= aim_time)
			break ;
		pthread_mutex_lock(&(monitor->m_finish));
		if (monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(monitor->m_finish));
			return ;
		}
		pthread_mutex_unlock(&(monitor->m_finish));
		usleep(unit);
	}
}

void	routine_takeoff_fork(t_philo *philo)
{
	philo->monitor->fork[philo->fork_left] = 0;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->fork_left]));
	philo->monitor->fork[philo->fork_right] = 0;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->fork_right]));
	return ;
}
