/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:41:21 by gcefalo           #+#    #+#             */
/*   Updated: 2021/08/23 19:55:56 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_data *data)
{
	if (data->philosopher)
		free(data->philosopher);
	if (data->forks)
		free(data->forks);
}

void	ft_destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n)
	{
		pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->execution);
}

void	ft_error(char *str, t_data *data)
{
	write(2, str, ft_strlen(str));
	ft_free_all(data);
	exit(-1);
}
