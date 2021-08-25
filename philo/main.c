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
