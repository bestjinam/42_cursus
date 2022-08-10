/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:06:07 by jinam             #+#    #+#             */
/*   Updated: 2022/08/10 21:11:06 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static int	_va_printf(va_list *ap, t_format *format, t_temp_str *t_str)
{
	const t_funcptr	fp[9] = {_printf_c, _printf_s, _printf_p};/*,
		_printf_d, _printf_d, _printf_u, _printf_x, _printf_xx, _printf_per}; */
	const char		*options = "cspdiuxX%";
	int				f_number;
	const char		option = format->specifier;

	f_number = ft_strchr(options, option) - options;
	return (fp[f_number](t_str, format, ap));
}

static void	_make_flags(t_format *format, char c)
{
	const char	*flags = "+- $0.";
	int			flags_idx;

	flags_idx = ft_strchr(flags, c) - flags;
	if (flags_idx >= 0)
		format->flags |= (1 << (flags_idx));
	else
		return ;
	if ((format->flags & PRECISION) == PRECISION
		|| ((format->flags & MINUS) == MINUS))
		format->flags &= ~ZERO;
	if ((format->flags & PLUS) == PLUS)
		format->flags &= ~SPACE;
}

static int	_parsing_flags(const char *str, t_format *format)
{
	static char	*options = "cspdiuxX%";
	int			i;

	i = 0;
	while (ft_strchr(options, str[i]) == 0)
	{
		if (!ft_isdigit(str[i])
			|| (str[i] == '0' && (i == 0 || (i != 0 && str[i - 1] != '.'))))
			_make_flags(format, str[i ++]);
		else
		{
			if (i != 0 && str[i - 1] == '.')
				format -> precision = ft_atoi(&str[i]);
			else
			{
				format -> width = ft_atoi(&str[i]);
				if (format < 0)
					return (-1);
			}
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	format->specifier = str[i++];
	return (i);
}

static int	_processing_printf(t_format *format, t_temp_str *t_str,
					va_list *ap, const char *str)
{
	int		i;
	int		res;
	int		temp;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != '%')
			temp = write(1, &str[i], 1);
		else
		{
			ft_string_clear(t_str);
			ft_memset(format, 0, sizeof(t_format));
			temp = _parsing_flags(&str[i + 1], format);
			if (temp == -1)
				return (0);
			i += temp;
			temp = _va_printf(ap, format, t_str);
		}
		if (temp < 0)
			return (-1);
		else
			res += temp;
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
	res = _processing_printf(&format, &temp_str, &ap, str);
	ft_string_delete(&temp_str);
	va_end(ap);
	return (res);
}
