/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:05:09 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/10 22:43:11 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	_pf_nbr_pre_process(t_format *format, t_temp_str *t_str, \
						unsigned long long n)
{
	if (format->specifier == 'X')
		ft_s_append(t_str, "0X");
	else
		ft_s_append(t_str, "0x");
}

void	_pf_nbr_noflag_process(t_format *format, t_temp_str *t_str, \
						unsigned long long n, char *base)
{
	const int	len = _pf_nbr_len(n, ft_strlen(base));
	const char	*conv_n = ft_itoa_base(n, base);
	int			pre;

	pre = 0;
	if (format->specifier == 'p' || (format->flags & PLUS) == PLUS)
		pre = 2;
	if (format->precision > len)
		_printf_width(t_str, format->width - (format->precision) - pre, ' ');
	else
		_printf_width(t_str, format->width - (len) - pre, ' ');
	_pf_nbr_pre_process(format, t_str, n);
	if ((format->flags & PRECISION) == PRECISION)
		_printf_width(t_str, format->precision - len, '0');
	ft_s_append(t_str, (char *)conv_n);
}
