/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:06:07 by jinam             #+#    #+#             */
/*   Updated: 2022/08/09 15:27:44 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static int	_va_printf(va_list ap, t_format *format, t_temp_str *t_str)
{
	static t_funcptr	fp[9] = {_printf_c, _printf_s, _printf_p,
		_printf_d, _printf_d, _printf_u, _printf_x, _printf_xx, _printf_per};
}

static int	_processing_printf(t_format *format, t_temp_str *t_str,
					va_list ap, const char *str)
{
	int		i;
	int		res;
	int		temp;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			ft_c_append(t_str, str[i++]);
		if (t_str->len > 0)
		{
			temp = ft_temp_print(t_str, 1);
			if (temp < 0)
				return (-1);
			res += temp;
		}
		if (str[i] == '%')
		{
			ft_memset(format, 0, sizeof(t_format));
			temp = _parsing_flags(&str[i + 1], format);
			if (temp < 0)
				return (-1);
			i += temp;
			_bit_mod_flags(format);
			temp = _va_printf(ap, format, t_str);
		}
		i ++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			res;
	t_format	format;
	t_temp_str	temp_str;

	va_start(ap, str);
	ft_string_init(&temp_str);
	res = _processing_printf(&format, &temp_str, ap, str);
	va_end(ap);
	return (res);
}
