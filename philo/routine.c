#include "philo.h"

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (msec_from_start(philo)
			- philo->time_last_meal > philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->data->print);
			printf("%d %d died\n", msec_from_start(philo), philo->philo_id);
			pthread_mutex_unlock(&philo->data->execution);
		}
		usleep(1000);
	}
}

void	ft_check_meals_goal(t_philo *philo)
{
	if (philo->data->meals_goal > 0 && philo->meals_amount >= 0)
	{
		(philo->meals_amount)++;
		if (philo->meals_amount == philo->data->meals_goal)
		{
			philo->data->goals_achieved++;
			if (philo->data->goals_achieved == philo->data->n)
			{
				pthread_mutex_lock(&philo->data->print);
				printf("Each philosopher ate at least %d times.\nGAME OVER\n",
					philo->data->meals_goal);
				pthread_mutex_unlock(&philo->data->execution);
				usleep(10000000);
			}
		}
	}
}

void	ft_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->fork_sx_id]);
	ft_print(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->data->forks[philo->fork_dx_id]);
	ft_print(philo, "has taken a fork\n");
	philo->time_last_meal = msec_from_start(philo);
	ft_print(philo, "is eating\n");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->goal_achieved);
	ft_check_meals_goal(philo);
	pthread_mutex_unlock(&philo->data->goal_achieved);
	ft_print(philo, "is sleeping\n");
	pthread_mutex_unlock(&philo->data->forks[philo->fork_sx_id]);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_dx_id]);
	usleep(philo->data->time_to_eat * 1000);
	ft_print(philo, "is thinking\n");
}

void	*ft_start_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death_thread_id;

	philo = (t_philo *)arg;
	pthread_create(&death_thread_id, NULL, check_death, arg);
	while (1)
	{
		ft_routine(philo);
	}
	return (0);
}

void	ft_start_game(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->execution);
	i = -1;
	while (++i < data->n)
	{
		if (pthread_create(&data->philosopher[i].thread_id, NULL,
				&ft_start_routine, (void *)&data->philosopher[i]))
			ft_error("Error:\nThread creation\n", data);
		usleep(100);
	}
	pthread_mutex_lock(&data->execution);
}
