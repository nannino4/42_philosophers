/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:57:17 by gcefalo           #+#    #+#             */
/*   Updated: 2021/08/23 20:07:33 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_msleep_eat(t_philo *philo)
{
	while (msec_from_start(philo) < philo->time_last_meal
		+ philo->data->time_to_eat)
	{
		usleep(EPSILON_USEC);
	}
}

void	ft_msleep_sleep(t_philo *philo)
{
	while (msec_from_start(philo) < philo->time_last_meal
		+ philo->data->time_to_eat + philo->data->time_to_sleep)
	{
		usleep(EPSILON_USEC);
	}
}
