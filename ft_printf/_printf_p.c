/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:18:34 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/11 00:51:24 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	_pf_base16_process(t_temp_str *t_str, t_format *f,
						long long n, char *base)
{
	f->flags &= ~SPACE;
	if ((f ->flags & PRECISION) == PRECISION && f -> precision == 0 && n == 0)
		_nbr_zero_precision_zero_process(f, t_str);
	if ((f ->flags & MINUS) == MINUS)
		_nbr_minus_process(f, t_str, n, base);
	else if ((f->flags & ZERO) == ZERO)
		_nbr_zero_process(f, t_str, n, base);
	else
		_nbr_noflag_process(f, t_str, n, base);
}

int	_printf_p(t_temp_str *t_str, t_format *format, va_list *ap)
{
	long long	pointer;

	pointer = (long long) va_arg(*ap, void *);
	_pf_base16_process(t_str, format, pointer, "0123456789abcdef");
	return (ft_temp_print(t_str, 1));
}
