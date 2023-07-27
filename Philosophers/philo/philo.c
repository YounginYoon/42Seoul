/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:14:13 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/27 17:10:46 by youyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_stat_printf(t_arg *arg, int id, char *msg)
{
	long long	now;

	pthread_mutex_lock(&(arg->print));
	now = get_time();
	if (now == -1)
		return (-1);
	if (!(arg->finish))
		printf("%lld %d %s\n", now - arg->start_time, id + 1, msg);
	if (ft_strncmp(msg, "died", 4) == 0)
		return (0);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}

int	ph_action(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	ph_stat_printf(arg, philo->id, "has taken a fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		ph_stat_printf(arg, philo->id, "has taken a fork");
		ph_stat_printf(arg, philo->id, "is eating");
		pthread_mutex_lock(&(arg->time));
		philo->last_eat_time = get_time();
		pthread_mutex_unlock(&(arg->time));
		philo->eat_count++;
		spend_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->right]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (0);
}

void	*ph_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2 == 0)
		sleep_until_even_eat(arg);
	while (!(arg->finish))
	{
		if (philo->id == arg->philo_num - 1 && philo->eat_count == 0)
			usleep(1);
		ph_action(arg, philo);
		if (arg->philo_num == 1)
			spend_time((long long)arg->time_to_sleep, arg);
		if (philo->eat_count == arg->least_eat_times)
		{
			arg->finished_eat++;
			break ;
		}
		ph_stat_printf(arg, philo->id, "is sleeping");
		spend_time((long long)arg->time_to_sleep, arg);
		ph_stat_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

void	ph_check_finish(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	while (!(arg->finish))
	{
		if ((arg->least_eat_times != 0) && \
			(arg->finished_eat == arg->philo_num))
		{
			arg->finish = 1;
			break ;
		}
		i = 0;
		while (i < arg->philo_num)
		{
			now = get_time();
			if ((now - philo[i].last_eat_time) >= arg->time_to_die)
			{
				ph_stat_printf(arg, i, "died");
				arg->finish = 1;
				break ;
			}
			i++;
		}
	}
}

int	ph_start(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
	{
		philo[i].last_eat_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL, ph_thread, &(philo[i])))
			return (1);
		i++;
	}
	ph_check_finish(arg, philo);
	i = 0;
	while (i < arg->philo_num)
		pthread_join(philo[i++].thread, NULL);
	return (0);
}
