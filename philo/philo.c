#include "philo.h"

int msec_from_start(t_philo *philo)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - philo->data->start_msec);
}

void    check_meal_condition(void)
{

}

void *give_life(void *arg)
{
    struct timeval tv;
    t_philo *philo;
    
    philo = (t_philo *)arg;
    while (1)
    {
        pthread_mutex_lock(&philo->data->forks[philo->fork_sx_id]);
        printf("%d %d has taken a fork\n", msec_from_start(philo), philo->philo_id);
        pthread_mutex_lock(&philo->data->forks[philo->fork_dx_id]);
        printf("%d %d has taken a fork\n", msec_from_start(philo), philo->philo_id);
        philo->time_last_meal = msec_from_start(philo);
        printf("%d %d is eating\n", msec_from_start(philo), philo->philo_id);
        usleep(philo->data->time_to_eat * 1000);
        if (philo->data->meals_goal >= 0 && philo->meals_amount < philo->data->meals_goal)
        {
            (philo->meals_amount)++;
            check_meals_condition();
        }
        printf("%d %d is sleeping\n", msec_from_start(philo), philo->philo_id);
        pthread_mutex_unlock(&philo->data->forks[philo->fork_sx_id]);
        pthread_mutex_unlock(&philo->data->forks[philo->fork_sx_id]);
        usleep(philo->data->time_to_sleep * 1000);
        printf("%d %d is thinking\n", msec_from_start(philo), philo->philo_id);
    }
}

void    start_game(t_data *data)
{
    int			    i;

    data->philosopher = malloc(data->n * sizeof(pthread_t));
    if (data->philosopher == NULL)
    {
        //error
    }
    data->forks = malloc(data->n * sizeof(pthread_mutex_t));
    if (data->forks == NULL)
    {
        //error
    }
    i = -1;
    while (++i < data->n)
    {
        pthread_create(&data->philosopher[i], NULL, &give_life, (void *)&i);
        pthread_mutex_init(&data->forks[i], NULL);
    }
    while (i-- > 0)
    {
        pthread_join(data->philosopher[i].thread_id, NULL);
        pthread_mutex_destroy(&data->forks[i]);
    }
}

int main(int argc, char **argv)
{
    t_data data;

    memset((void *)&data, 0, sizeof(t_data));
    ft_parse_argv(argc, argv);
    ft_init_struct(&data, argv);
	ft_start_game(&data);
	ft_exit(&data);
	return (0);
}
