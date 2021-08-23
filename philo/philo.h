#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define EPSILON_USEC 50

typedef struct s_philo {
	int				philo_id;
	int				meals_amount;
	int				time_last_meal;
	int				fork_sx_id;
	int				fork_dx_id;
	struct s_data	*data;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_data
{
    int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_goal;
	long long		start_msec;
	t_philo			*philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	execution;
	int				goals_achieved;
}   t_data;

void	ft_parse(int argc, char **argv);
void	ft_initialize(t_data *data, char **argv);
int	ft_atoi(const char *str);
void	ft_error(char *str, t_data *data);
void	ft_exit(t_data *data, int n);
int	ft_isnum(char *str);
void	ft_print(t_philo *philo, char *str);
long int get_time(void);
int ft_strlen(char *s);
int msec_from_start(t_philo *philo);
void	ft_free_all(t_data *data);
void	ft_destroy_mutex(t_data *data);
void ft_msleep(t_philo *philo, int start, int time_to_sleep);

#endif
