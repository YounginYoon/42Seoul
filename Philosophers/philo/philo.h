/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:51:12 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/27 15:15:00 by youyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAIL 1

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				least_eat_times;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	time;
}	t_arg;

typedef struct s_philo
{
	t_arg			*arg;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
}	t_philo;

/* init.c */
int			init_mutex(t_arg *arg);
int			init_args(t_arg *arg, int argc, char **argv);
int			init_philo(t_philo **philo, t_arg *arg);

/* utils.c */
int			ft_atoi(const char *str);
long long	get_time(void);

/* philo.c */
int			ph_start(t_arg *arg, t_philo *philo);
#endif