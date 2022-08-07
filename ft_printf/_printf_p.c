/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/07 14:07:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_nbr_len(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		i ++;
	}
	return (i);
}

static int	_p_plain_process_width(t_format *format, int len)
{
	int	res2;
	int	pre;

	if (format->specifier == 'p' || (format->flags & 010) == 010)
		pre = 2;
	else
		pre = 0;
	if (format->precision > len)
		res2 = _printf_p_width(format->width - (format->precision) - pre, ' ');
	else
		res2 = _printf_p_width(format->width - (len) - pre, ' ');
	if (res2 < 0)
		return (-1);
	return (res2);
}

int	_p_plain_process(t_format *format, unsigned long nbr, int len, char *base)
{
	int		res2;
	int		tmp;

	res2 = _p_plain_process_width(format, len);
	if (res2 < 0)
		return (-1);
	tmp = _p_prenumber_print(format, nbr);
	if (tmp < 0)
		return (-1);
	res2 += tmp;
	if ((format->flags & 040) == 040)
	{
		tmp = _printf_p_width(format->precision - len, '0');
		if (tmp < 0)
			return (-1);
		res2 += tmp;
	}
	tmp = _convert_base(nbr, base);
	if (tmp < 0)
		return (-1);
	return (res2 + tmp);
}

int	_printf_base16_process(t_format *format, unsigned long nbr, char *base)
{
	int	nbr_len;
	int	idx;

	nbr_len = _nbr_len(nbr);
	idx = 0;
	format->flags &= ~05;
	if ((format->flags & 040) == 040 && format->precision == 0 && nbr == 0)
		return (_p_zero_precision_zero_process(format));
	if ((format->flags & 02) == 02)
		return (_p_minus_process(format, nbr, nbr_len, (char *) base));
	else if ((format->flags & 020) == 020)
		return (_p_zero_process(format, nbr, nbr_len, (char *) base));
	else
		return (_p_plain_process(format, nbr, nbr_len, (char *) base));
}

int	_printf_p(t_format *format, va_list ap)
{
	unsigned long	pointer;

	pointer = (unsigned long) va_arg(ap, void *);
	return (_printf_base16_process(format, pointer, "0123456789abcdef"));
}
