/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:11:39 by jinam             #+#    #+#             */
/*   Updated: 2022/08/05 21:14:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static void	_printf_c_width(char *res_char, int width)
{
	if (width == 0)
		return ;
	while (width)
	{
		*res_char = ' ';
		res_char ++;
		width --;
	}
}

static void	_precision_make(t_format *format, char *str, int str_len)
{
	if ((format->flags & 02) == 02)
	{
		ft_memmove(&format->str[0], str, str_len);
		_printf_c_width(&format->str[str_len], format->space_size - str_len);
	}
	else
	{
		_printf_c_width(&format->str[0], format->space_size - str_len);
		ft_memmove(&format->str[format->space_size - str_len], str, str_len);
	}
}

static void	_printf_s_make_str(t_format *format, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (!format->precision && (format->flags & 040) == 040)
		_printf_c_width(format->str, format->width);
	else if (!(format->flags & 040))
		_precision_make(format, str, str_len);
	else
	{
		if (format->precision >= str_len)
			_precision_make(format, str, str_len);
		else
			_precision_make(format, str, format->precision);
	}
	return ;
}

static int	_printf_s_print(char *str)
{
	int	res;
	int	tmp;

	res = 0;
	while (*str)
	{
		tmp = write(1, str, 1);
		if (!tmp)
			return (-1);
		else
			res += tmp;
		str ++;
	}
	return (res);
}

int	_printf_s(t_format *format, va_list ap)
{
	char	*str;
	int		res;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	res = 0;
	if ((format->flags & 040) && format->precision < (int) ft_strlen(str))
		format->space_size = _init_str(format, format->precision);
	else
		format->space_size = _init_str(format, ft_strlen(str));
	if (!format->str)
		return (-1);
	_printf_s_make_str(format, str);
	res = _printf_s_print(format->str);
	free(format->str);
	return (res);
}
