/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:00:38 by jinam             #+#    #+#             */
/*   Updated: 2022/08/05 20:52:44 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	_printf_c_width(char *res_char, int width)
{
	if (width == 0)
		return ;
	while (width - 1)
	{
		*res_char = ' ';
		res_char ++;
		width --;
	}
}

static void	_printf_c_make_str(t_format *format, char c)
{
	if ((format->flags & 02) == 02)
	{
		format->str[0] = c;
		_printf_c_width(&format->str[1], format->width);
	}
	else
	{
		_printf_c_width(&format->str[0], format->width);
		format->str[format->space_size - 1] = c;
	}
}

int	_printf_c(t_format *format, va_list ap)
{
	char		c;
	int			res;

	c = (char) va_arg(ap, int);
	format->space_size = _init_str(format, 1);
	if (!format->str)
		return (-1);
	_printf_c_make_str(format, c);
	res = 0;
	while (res < format->space_size)
	{
		if (write(1, &format->str[res], 1) == -1)
			return (-1);
		else
			res ++;
	}
	free(format->str);
	return (res);
}
