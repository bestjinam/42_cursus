/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:00:09 by jinam             #+#    #+#             */
/*   Updated: 2022/08/06 18:53:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static int	_va_printf(va_list ap, t_format *format)
{
	static t_funcptr	fp[9] = {_printf_c, _printf_s, _printf_p,
		_printf_d, _printf_d, _printf_u, _printf_x, _printf_xx, _printf_per};
	static char			*options = "cspdiuxX%";
	int					f_number;
	const char			option = format->specifier;

	f_number = ft_strchr(options, option) - options;
	return (fp[f_number](format, ap));
}

static int	_processing_printf(va_list ap, const char *str)
{
	int			i;
	int			res;
	t_format	format;
	int			temp;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != '%')
			temp = write(1, &str[i], 1);
		else
		{
			ft_memset(&format, 0, sizeof(t_format));
			i += _parsing_flags(&str[i + 1], &format);
			_bit_mod_flags(&format);
			temp = _va_printf(ap, &format);
		}
		if (temp < 0)
			return (-1);
		else
			res += temp;
		i ++;
	}
	va_end(ap);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int			res;
	va_list		ap;

	va_start(ap, str);
	res = _processing_printf(ap, str);
	va_end(ap);
	return (res);
}
