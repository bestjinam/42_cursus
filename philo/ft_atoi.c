/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:02:49 by jinam             #+#    #+#             */
/*   Updated: 2023/02/13 17:06:50 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

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
		res += (str[idx] - '0');
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
		i ++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
	}
	return (_atoi_conv(str + i, sign));
}
