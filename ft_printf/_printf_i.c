/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/04 22:41:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_i(t_format *format, va_list ap)
{
	(void) format;
	long	nbr;
	int		res1;
	int		res2;

	nbr = (long) va_arg(ap, int);
	res1 = 0;
	if (nbr < 0)
	{
		res1 += write(1, "-", 1);
		nbr *= -1;
	}
	res2 = _convert_base(nbr, "0123456789");
	if (res1 == -1 || res2 == -1)
		return (-1);
	return (res1 + res2);
}
