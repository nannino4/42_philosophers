/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:42:36 by gcefalo           #+#    #+#             */
/*   Updated: 2021/08/23 20:05:06 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->fork_sx_id]);
	ft_print(philo, "has taken a fork\n");
	while (philo->data->n == 1)
		usleep(philo->data->time_to_die * 10000);
	pthread_mutex_lock(&philo->data->forks[philo->fork_dx_id]);
	ft_print(philo, "has taken a fork\n");
	philo->time_last_meal = msec_from_start(philo);
	ft_print(philo, "is eating\n");
	ft_msleep_eat(philo);
	if (philo->data->meals_goal >= 0 && philo->meals_amount >= 0)
		(philo->meals_amount)++;
	if (philo->meals_amount == philo->data->meals_goal)
		philo->data->goals_achieved++;
	if (philo->data->goals_achieved == philo->data->n)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("Each philosopher ate at least %d times.\nGAME OVER\n",
			philo->data->meals_goal);
		pthread_mutex_unlock(&philo->data->execution);
	}
	ft_print(philo, "is sleeping\n");
	pthread_mutex_unlock(&philo->data->forks[philo->fork_sx_id]);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_dx_id]);
	ft_msleep_sleep(philo);
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
		usleep(5);
	}
	pthread_mutex_lock(&data->execution);
	pthread_mutex_unlock(&data->execution);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset((void *)&data, 0, sizeof(t_data));
	ft_parse(argc, argv);
	ft_initialize(&data, argv);
	ft_start_game(&data);
	ft_destroy_mutex(&data);
	ft_free_all(&data);
	return (0);
}
