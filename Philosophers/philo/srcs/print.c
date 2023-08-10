/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:19:55 by youyoon           #+#    #+#             */
/*   Updated: 2023/08/10 13:19:55 by youyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_take_fork_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	time_stamp = calculate_timeval(&(philo->monitor->start_time), &(curr_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\thas taken a fork\n", time_stamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_eat_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	time_stamp = calculate_timeval(&(philo->monitor->start_time), &(curr_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\tis eating\n", time_stamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_sleep_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	time_stamp = calculate_timeval(&(philo->monitor->start_time), &(curr_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\tis sleeping\n", time_stamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_think_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	time_stamp = calculate_timeval(&(philo->monitor->start_time), &(curr_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\tis thinking\n", time_stamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_finish_state(t_philo *philo, int status)
{
	long			time_stamp;
	struct timeval	curr_time;

	pthread_mutex_lock(&(philo->monitor->m_finish));
	philo->monitor->finish_flag = 1;
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (1);
	}
	time_stamp = calculate_timeval(&(philo->monitor->start_time), &(curr_time));
	pthread_mutex_lock(&(philo->monitor->m_print));
	if (status == DIE)
		printf("%ld\t%d\tis died\n", time_stamp, philo->id + 1);
	else if (status == FULL)
		printf("%ld\tall philosophers are full\n", time_stamp);
	pthread_mutex_unlock(&(philo->monitor->m_print));
	return (1);
}
