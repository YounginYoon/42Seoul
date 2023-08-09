#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define DIE 0
# define FULL 1

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		m_last_eat;
	long				last_eat;
	pthread_mutex_t		m_cnt_eat;
	int					cnt_eat;
	int					fork_left;
	int					fork_right;
	struct s_monitor	*monitor;
}	t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	m_start;
	int				num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_flag;
	int				must_eat;
	pthread_mutex_t	m_finish;
	int				finish_flag;
	struct timeval	start_time;
	pthread_t		*thread;
	t_philo			*philo;
	pthread_mutex_t	*m_fork;
	int				*fork;
	pthread_mutex_t	m_print;
}	t_monitor;

/* utils.c */
int		ft_atoi(const char *str);
void	swap_fork(t_philo *philo);
long	calculate_timeval(struct timeval *start, struct timeval *end);
void	sleep_unit(t_monitor *monitor, long	aim_time, \
						struct timeval start_time, long unit);
void	routine_takeoff_fork(t_philo *philo);

/* init.c */
int		init_monitor(t_monitor	*monitor, int argc, char **argv);

/* main.c */
int		print_error(char *msg);
int		init_start_fin_mutex(t_monitor *monitor);

/* free_mem.c */
int		free_philo(t_monitor *monitor, int philo_num);
void	free_fork(t_monitor *monitor, int philo_num);
void	join_thread(t_monitor *monitor);
int		free_monitor(t_monitor *monitor);

/* monitor.c */
int		monitor_philo(t_monitor *monitor);

/* print.c */
int		print_take_fork_state(t_philo *philo);
int		print_eat_state(t_philo *philo);
int		print_sleep_state(t_philo *philo);
int		print_think_state(t_philo *philo);
int		print_finish_state(t_philo *philo, int status);

/* routine_one.c */
void	*routine_one(void *arg);

/* routine.c */
void	*routine(void *arg);

#endif