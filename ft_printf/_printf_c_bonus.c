/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:34:32 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/23 19:46:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	_printf_width_append(t_temp_str *t_str, char c, int width)
{
	if (width == 0)
		return ;
	while (width - 1)
	{
		ft_c_append(t_str, c);
		width --;
	}
}

int	_printf_c(t_temp_str *t_str, t_format *format, va_list *ap)
{
	char	c;

	c = (char) va_arg(*ap, int);
	ft_string_clear(t_str);
	if ((format->flags & MINUS) == MINUS)
	{
		ft_c_append(t_str, c);
		_printf_width_append(t_str, ' ', format->width);
	}
	else
	{
		_printf_width_append(t_str, ' ', format->width);
		ft_c_append(t_str, c);
	}
	return (ft_temp_print(t_str, 1));
}
