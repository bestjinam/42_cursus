/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:00:38 by jinam             #+#    #+#             */
/*   Updated: 2022/08/07 14:22:57 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_printf_per_minus_print(int width)
{
	int	res;
	int	tmp;

	res = 0;
	if (write(1, "\%", 1) == -1)
		return (-1);
	res += 1;
	tmp = _printf_d_width(width - 1, ' ');
	if (tmp < 0)
		return (-1);
	return (res + tmp);
}

static int	_printf_per_width_print(int width)
{
	int	res;
	int	tmp;

	res = 0;
	tmp = _printf_d_width(width - 1, ' ');
	if (tmp < 0)
		return (-1);
	res += tmp;
	if (write(1, "\%", 1) == -1)
		return (-1);
	res ++;
	return (res);
}

static int	_printf_per_basic_print(void)
{
	return (write(1, "\%", 1));
}

int	_printf_per(t_format *format, va_list ap)
{
	(void) ap;
	if ((format->flags & 02) == 02 && format->width > 1)
		return (_printf_per_minus_print(format->width));
	else if (format->width > 1)
		return (_printf_per_width_print(format->width));
	else
		return (_printf_per_basic_print());
}
