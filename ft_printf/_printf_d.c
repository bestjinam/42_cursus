/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/05 21:42:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	_printf_d_width(char *res_char, int width, char c)
{
	if (width == 0)
		return ;
	while (width - 1)
	{
		*res_char = c;
		res_char ++;
		width --;
	}
}

static int	_print_sign(t_format *format, long nbr)
{
	int	res1;

	res1 = 0;
	if (nbr < 0)
		res1 += write(1, "-", 1);
	else if ((format->flags & 01) == 01 || (format -> flags & 04) == 04)
		res1 += write(1, "+", 1);
	return (res1);
}

int	_printf_d(t_format *format, va_list ap)
{
	long	nbr;
	int		res1;
	int		res2;

	nbr = (long) va_arg(ap, int);
	res1 = _print_sign(format, nbr);
	res2 = _convert_base(nbr * ((nbr > 0) - (nbr < 0)), "0123456789");
	if (res1 == -1 || res2 == -1)
		return (-1);
	return (res1 + res2);
}
