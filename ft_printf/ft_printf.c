/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:00:09 by jinam             #+#    #+#             */
/*   Updated: 2022/08/03 11:43:28 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static int	_va_printf(va_list ap, int option)
{
	static t_funcptr	fp[9] = {_printf_c, _printf_s, _printf_p,
		_printf_d, _printf_i, _printf_u, _printf_x, _printf_xx, _printf_per};
	static char			*options = "cspdiuxX%";
	int					f_number;

	f_number = ft_strchr(options, option) - options;
	return (fp[f_number](ap));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	int		temp;
	va_list	ap;

	i = 0;
	res = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			temp = write(1, &str[i], 1);
		else
			temp = _va_printf(ap, str[++i]);
		if (temp < 0)
			return (-1);
		else
			res += temp;
		i ++;
	}
	return (res);
}

