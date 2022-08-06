/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:00:38 by jinam             #+#    #+#             */
/*   Updated: 2022/08/06 23:27:36 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_per(t_format *format, va_list ap)
{
	int	tmp;
	int	res;

	(void) ap;
	res = 0;
	if ((format->flags & 02) == 02 && format->width > 1)
	{
		tmp = write(1, "\%", 1);
		if (tmp < 0)
			return (-1);
		res += tmp;
		tmp = _printf_d_width(format->width - 1, ' ');
		if (tmp < 0)
			return (-1);
		return (res + tmp);
}
	else if (format->width > 1)
	{
		tmp = _printf_d_width(format->width - 1, ' ');
		if (tmp < 0)
			return (-1);
		res += tmp;
		tmp = write(1, "\%", 1);
		if (tmp < 0)
			return (-1);
		return (res + tmp);
	}
	return (write(1, "\%", 1));
}
