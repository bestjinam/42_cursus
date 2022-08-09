/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:39:33 by jinam             #+#    #+#             */
/*   Updated: 2022/08/07 16:52:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_print_sign(t_format *format, long nbr)
{
	int	res1;

	res1 = 0;
	if (nbr < 0)
		res1 += write(1, "-", 1);
	else if ((format->flags & 01) == 01)
		res1 += write(1, "+", 1);
	else if ((format->flags & 04) == 04)
		res1 += write(1, " ", 1);
	return (res1);
}

int	_printf_d_minus_process(t_format *format, long nbr, int len, char *base)
{
	int	res1;
	int	res2;
	int	tmp;

	res1 = _print_sign(format, nbr);
	if (res1 < 0)
		return (-1);
	res2 = 0;
	if ((format->flags & 040) == 040)
	{
		res2 = _printf_d_width(format->precision - len, '0');
		if (res2 < 0)
			return (-1);
	}
	tmp = _convert_base(nbr * ((nbr > 0) - (nbr < 0)), base);
	if (tmp < 0)
		return (-1);
	res2 += tmp;
	tmp = _printf_d_width(format->width - (res1 + res2), ' ');
	if (tmp < 0)
		return (-1);
	return (res1 + res2 + tmp);
}

int	_printf_d_zero_process(t_format *format, long nbr, int len, char *base)
{
	int	res1;
	int	res2;
	int	tmp;

	res1 = _print_sign(format, nbr);
	if (res1 < 0)
		return (-1);
	res2 = _printf_d_width(format->width - (len + res1), '0');
	if (res2 < 0)
		return (-1);
	tmp = _convert_base(nbr * ((nbr > 0) - (nbr < 0)), (char *)base);
	if (tmp < 0)
		return (-1);
	return (res1 + res2 + tmp);
}

static int	__plain_width_process(t_format *format, int len, int res1, char c)
{
	int	res2;

	if (format->precision > len)
		res2 = _printf_d_width(format->width - (res1 + format->precision), c);
	else
		res2 = _printf_d_width(format->width - (len + res1), c);
	if (res2 < 0)
		return (-1);
	return (res2);
}

int	_printf_d_plain_process(t_format *format, long nbr, int len, char *base)
{
	int		res1;
	int		res2;
	int		tmp;

	res1 = ((nbr < 0) || (format->flags & 01) == 01 || \
			(format->flags & 04) == 04);
	res2 = __plain_width_process(format, len, res1, ' ');
	if (res2 < 0)
		return (-1);
	res1 = _print_sign(format, nbr);
	if (res1 < 0)
		return (-1);
	if ((format->flags & 040) == 040)
	{
		tmp = _printf_d_width(format->precision - len, '0');
		if (tmp < 0)
			return (-1);
		res2 += tmp;
	}
	tmp = _convert_base(nbr * ((nbr > 0) - (nbr < 0)), base);
	if (tmp < 0)
		return (-1);
	return (res1 + res2 + tmp);
}
