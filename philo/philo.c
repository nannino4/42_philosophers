#include "philo.h"

void    *check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (msec_from_start(philo) - philo->time_last_meal > philo->data->time_to_die)
		{
			ft_print(philo, "died");
            ft_exit(philo->data, 1);
		}
		usleep(1000);
	}
}

void ft_routine(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->fork_sx_id]);
    ft_print(philo, "has taken a fork\n");
    while (philo->data->n == 1)
        usleep(1000000);
    pthread_mutex_lock(&philo->data->forks[philo->fork_dx_id]);
    ft_print(philo, "has taken a fork\n");
    philo->time_last_meal = msec_from_start(philo);
    ft_print(philo, "is eating\n");
    usleep(philo->data->time_to_eat * 1000);
    if (philo->data->meals_goal >= 0 && philo->meals_amount < philo->data->meals_goal)
        (philo->meals_amount)++;
    if (philo->meals_amount == philo->data->meals_goal)
        philo->data->goals_achieved++;
    if (philo->data->goals_achieved == philo->data->n)
    {
        pthread_mutex_lock(&philo->data->print);
        printf("Each philosopher ate at least %d times.\nGAME OVER\n", philo->data->meals_goal);
        ft_exit(philo->data, 0);
    }
    ft_print(philo, "is sleeping\n");
    pthread_mutex_unlock(&philo->data->forks[philo->fork_sx_id]);
    pthread_mutex_unlock(&philo->data->forks[philo->fork_sx_id]);
    usleep(philo->data->time_to_sleep * 1000);
    ft_print(philo, "is thinking\n");
}

void *ft_start_routine(void *arg)
{
    t_philo *philo;
    pthread_t death_thread_id;
    
    philo = (t_philo *)arg;
	pthread_create(&death_thread_id, NULL, check_death, philo);
    while (1)
    {
        ft_routine(philo);
    }
    return (0);
}

void    ft_start_game(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->n)
    {
        if(pthread_create(&data->philosopher[i].thread_id, NULL, &ft_start_routine, (void *)&i))
            ft_error("Error:\nThread creation\n", data);
        usleep(50);
    }
}

int main(int argc, char **argv)
{
    t_data data;

    memset((void *)&data, 0, sizeof(t_data));
    ft_parse(argc, argv);
    ft_initialize(&data, argv);
	ft_start_game(&data);
	return (0);
}
