/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:05:09 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/11 00:35:21 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	_pf_nbr_pre_process(t_format *format, t_temp_str *t_str)
{
	if (format->specifier == 'X')
		ft_s_append(t_str, "0X");
	else
		ft_s_append(t_str, "0x");
}

void	_nbr_noflag_process(t_format *format, t_temp_str *t_str, \
						unsigned long n, char *base)
{
	const int	len = _pf_nbr_len(n, ft_strlen(base));
	char		*conv_n;
	int			pre;

	pre = 0;
	conv_n = ft_itoa_base(n, base);
	printf("%s\n", conv_n);
	if (format->specifier == 'p' || (format->flags & PLUS) == PLUS)
		pre = 2;
	if (format->precision > len)
		_printf_width(t_str, format->width - (format->precision) - pre, ' ');
	else
		_printf_width(t_str, format->width - (len) - pre, ' ');
	_pf_nbr_pre_process(format, t_str);
	if ((format->flags & PRECISION) == PRECISION)
		_printf_width(t_str, format->precision - len, '0');
	ft_s_append(t_str, (char *)conv_n);
	free((void *)conv_n);
}

void	_nbr_zero_process(t_format *format, t_temp_str *t_str, \
						unsigned long long n, char *base)
{
	const int	len = _pf_nbr_len(n, ft_strlen(base));
	const char	*conv_n = ft_itoa_base(n, base);

	_pf_nbr_pre_process(format, t_str);
	_printf_width(t_str, (format->width - len - 2), '0');
	ft_s_append(t_str, (char *)conv_n);
	free((void *)conv_n);
}

void	_nbr_zero_precision_zero_process(t_format *format, t_temp_str *t_str)
{
	_printf_width(t_str, (format->width), ' ');
}

void	_nbr_minus_process(t_format *format, t_temp_str *t_str, \
						unsigned long long n, char *base)
{
	const int	len = _pf_nbr_len(n, ft_strlen(base));
	const char	*conv_n = ft_itoa_base(n, base);

	_pf_nbr_pre_process(format, t_str);
	if ((format->flags & PRECISION) == PRECISION)
		_printf_width(t_str, (format->precision - len), '0');
	ft_s_append(t_str, (char *) conv_n);
	free((void *)conv_n);
	_printf_width(t_str, (format->width - t_str->len), ' ');
}
