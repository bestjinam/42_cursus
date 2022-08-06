/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_d_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:30:40 by jinam             #+#    #+#             */
/*   Updated: 2022/08/06 17:45:09 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_printf_d_zero_precision_zero_process(t_format *format)
{
	int	res1;
	int	res2;

	res1 = ((format->flags & 01) == 01 || (format->flags & 04) == 04);
	if ((format->flags & 02) == 02)
	{
		res1 = _print_sign(format, 0);
		if (res1 < 0)
			return (-1);
		res2 = _printf_d_width(format->width - res1, ' ');
		if (res2 < 0)
			return (-1);
	}
	else
	{
		res2 = _printf_d_width(format->width - res1, ' ');
		if (res2 < 0)
			return (-1);
		res1 = _print_sign(format, 0);
		if (res1 < 0)
			return (-1);
	}
	return (res1 + res2);
}
