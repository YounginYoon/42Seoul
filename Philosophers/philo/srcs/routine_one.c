/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:19:59 by youyoon           #+#    #+#             */
/*   Updated: 2023/08/10 13:19:59 by youyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine_take_fork_left(t_philo *philo)
{
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->fork_left]));
	philo->monitor->fork[philo->fork_left] = 1;
	if (print_take_fork_state(philo) < 0)
	{
		philo->monitor->fork[philo->fork_left] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->fork_left]));
		return ;
	}
}

static void	routine_take_fork_right(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		if (philo->monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			philo->monitor->fork[philo->fork_left] = 0;
			pthread_mutex_unlock(&(philo->monitor->m_fork[philo->fork_left]));
			return ;
		}
		if (philo->monitor->fork[philo->fork_right] == 0)
		{
			philo->monitor->fork[philo->fork_right] = 1;
			pthread_mutex_lock(&(philo->monitor->m_fork[philo->fork_right]));
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->monitor->m_finish));
	}
	if (print_take_fork_state(philo) < 0)
		routine_takeoff_fork(philo);
}

static void	routine_eat(t_philo *philo)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return ;
	}
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->last_eat = calculate_timeval(&(philo->monitor->start_time), \
						&curr_time);
	pthread_mutex_unlock(&(philo->m_last_eat));
	if (print_eat_state(philo) < 0)
	{
		routine_takeoff_fork(philo);
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, curr_time, 200);
	pthread_mutex_lock(&(philo->m_cnt_eat));
	(philo->cnt_eat)++;
	pthread_mutex_unlock(&(philo->m_cnt_eat));
}

static void	routine_sleep(t_philo *philo)
{
	struct timeval	start_time;

	if (print_sleep_state(philo) < 0)
		return ;
	if (gettimeofday(&(start_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 200);
}

void	*routine_one(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->monitor->m_start));
	pthread_mutex_unlock(&(philo->monitor->m_start));
	while (1)
	{
		routine_take_fork_left(philo);
		routine_take_fork_right(philo);
		routine_eat(philo);
		routine_takeoff_fork(philo);
		routine_sleep(philo);
		print_think_state(philo);
		pthread_mutex_lock(&(philo->monitor->m_finish));
		if (philo->monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		usleep(50);
	}
	return (0);
}
