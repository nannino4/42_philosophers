#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

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
	int				game_over;
}   t_data

#endif
