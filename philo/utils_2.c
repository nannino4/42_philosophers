/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:01:32 by gcefalo           #+#    #+#             */
/*   Updated: 2021/09/06 12:01:32 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isspace(char c)
{
	if (c == '\n' || c == '\r' || c == '\f' || c == '\t' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

static	int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static	int	is_char_int(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static	int	get_result(const char *str, long res, int s)
{
	while (is_char_int(*str))
	{
		res = res * 10 + (*str - '0');
		if (s == -1 && res > 2147483648)
			return (0);
		if (s == 1 && res > 2147483647)
			return (-1);
		str++;
	}
	return ((int)(res * s));
}

int	ft_atoi(const char *str)
{
	int		s;
	long	res;

	s = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	while (is_sign(*str))
	{
		if (*(str++) == '-')
			s = -1;
		break ;
	}
	return (get_result(str, res, s));
}
