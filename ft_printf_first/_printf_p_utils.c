/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_p_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:39:33 by jinam             #+#    #+#             */
/*   Updated: 2022/08/07 14:07:30 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_p_width(int width, char c)
{
	int	tmp;
	int	res;

	res = 0;
	if (width <= 0)
		return (0);
	while (width)
	{
		tmp = write(1, &c, 1);
		if (tmp < 0)
			return (-1);
		else
			res += tmp;
		width --;
	}
	return (res);
}

int	_p_prenumber_print(t_format *format, unsigned long nbr)
{
	int		idx;
	int		res1;
	char	*pre;

	idx = 0;
	res1 = 0;
	if (format->specifier == 'X')
		pre = "0X";
	else
		pre = "0x";
	if (!((format->flags & 040) == 040 && format->precision == 0 && nbr == 0))
	{
		while (idx < 2)
		{
			if (write(1, &pre[idx], 1) == -1)
				return (-1);
			else
				res1 ++;
			idx ++;
		}
	}
	return (res1);
}

int	_p_minus_process(t_format *format, unsigned long nbr, int len, char *base)
{
	int		res2;
	int		tmp;

	res2 = _p_prenumber_print(format, nbr);
	if (res2 < 0)
		return (-1);
	if ((format->flags & 040) == 040)
	{
		tmp = _printf_p_width(format->precision - len, '0');
		if (tmp < 0)
			return (-1);
		res2 += tmp;
	}
	tmp = _convert_base(nbr, base);
	if (tmp == -1)
		return (-1);
	res2 += tmp;
	tmp = _printf_p_width(format->width - res2, ' ');
	if (tmp < 0)
		return (-1);
	res2 += tmp;
	return (res2);
}

int	_p_zero_process(t_format *format, unsigned long nbr, int len, char *base)
{
	int	res2;
	int	tmp;

	res2 = _p_prenumber_print(format, nbr);
	if (res2 < 0)
		return (-1);
	tmp = _printf_p_width(format->width - (len) - res2, '0');
	if (tmp < 0)
		return (-1);
	res2 += tmp;
	tmp = _convert_base(nbr, (char *)base);
	if (tmp < 0)
		return (-1);
	res2 += tmp;
	return (res2);
}

int	_p_zero_precision_zero_process(t_format *format)
{
	int	res2;

	res2 = _printf_p_width(format->width, ' ');
	if (res2 < 0)
		return (-1);
	return (res2);
}
