/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:55:33 by gcefalo           #+#    #+#             */
/*   Updated: 2021/08/23 20:01:33 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_parse(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		write(2, "Error:\nInvalid arguments\n",
			ft_strlen("Error:\nInvalid arguments\n"));
		exit(-1);
	}
	while (argv[++i])
	{
		if (ft_isnum(argv[i]))
		{
			write(2, "Error:\nInvalid arguments\n",
				ft_strlen("Error:\nInvalid arguments\n"));
			exit(-1);
		}
	}
}
