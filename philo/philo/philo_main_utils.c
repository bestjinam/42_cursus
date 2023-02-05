/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:38:48 by jinam             #+#    #+#             */
/*   Updated: 2023/02/03 15:42:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	_isspace(int c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

static int	_atoi_conv(const char *str, int sign)
{
	int		res;
	size_t	idx;

	res = 0;
	idx = 0;
	while (ft_isdigit(str[idx]))
	{
		res *= 10;
		res += (str[idx] - '0') * sign;
		idx ++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;

	i = 0;
	while (_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
	}
	return (_atoi_conv(str + i, sign));
}
