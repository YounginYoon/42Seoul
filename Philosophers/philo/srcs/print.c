#include "philo.h"

int	print_take_fork_state(t_philo *philo)
{
	long			timestamp;
	struct timeval	cur_time;

	if (gettimeofday(&(cur_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	timestamp = calculate_timeval(&(philo->monitor->start_time), &(cur_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\thas taken a fork\n", timestamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_eat_state(t_philo *philo)
{
	long			timestamp;
	struct timeval	cur_time;

	if (gettimeofday(&(cur_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	timestamp = calculate_timeval(&(philo->monitor->start_time), &(cur_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\tis eating\n", timestamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_sleep_state(t_philo *philo)
{
	long			timestamp;
	struct timeval	cur_time;

	if (gettimeofday(&(cur_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	timestamp = calculate_timeval(&(philo->monitor->start_time), &(cur_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\tis sleeping\n", timestamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_think_state(t_philo *philo)
{
	long			timestamp;
	struct timeval	cur_time;

	if (gettimeofday(&(cur_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	timestamp = calculate_timeval(&(philo->monitor->start_time), &(cur_time));
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf("%ld\t%d\tis thinking\n", timestamp, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_finish_state(t_philo *philo, int status)
{
	long			timestamp;
	struct timeval	cur_time;

	pthread_mutex_lock(&(philo->monitor->m_finish));
	philo->monitor->finish_flag = 1;
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	if (gettimeofday(&(cur_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (1);
	}
	timestamp = calculate_timeval(&(philo->monitor->start_time), &(cur_time));
	pthread_mutex_lock(&(philo->monitor->m_print));
	if (status == DIE)
		printf("%ld\t%d\tis died\n", timestamp, philo->id + 1);
	else if (status == FULL)
		printf("%ld\tall philosophers are full\n", timestamp);
	pthread_mutex_unlock(&(philo->monitor->m_print));
	return (1);
}