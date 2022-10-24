/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:23:06 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 16:30:16 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *temp_str)
{
	size_t			res;
	size_t			tmp;
	const size_t	len = ft_strlen(temp_str);

	res = 0;
	while (1)
	{
		tmp = write(1, &temp_str[res], (len - res));
		if (tmp < 0)
			return (-1);
		res += tmp;
		if (res == len)
			return (res);
	}
}

static void	_write_nbr(long nbr)
{
	if (nbr > 9)
		_write_nbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = (long) n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	_write_nbr(nbr);
}
