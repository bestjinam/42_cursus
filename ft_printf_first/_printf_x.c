/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/08 21:24:32 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_nbr_len(unsigned int nbr)
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

int	_printf_x(t_format *format, va_list ap)
{
	unsigned int	nbr;
	int				nbr_len;
	const char		*base = "0123456789abcdef";

	nbr = va_arg(ap, unsigned int);
	nbr_len = _nbr_len(nbr);
	format->flags &= ~05;
	if ((format->flags & 010) == 010 && nbr != 0)
		return (_printf_base16_process(format, nbr, (char *)base));
	if ((format->flags & 040) == 040 && format->precision == 0 && nbr == 0)
		return (_printf_d_zero_precision_zero_process(format));
	if ((format->flags & 02) == 02)
		return (_printf_d_minus_process(format, nbr, nbr_len, (char *) base));
	else if ((format->flags & 020) == 020)
		return (_printf_d_zero_process(format, nbr, nbr_len, (char *) base));
	else
		return (_printf_d_plain_process(format, nbr, nbr_len, (char *) base));
}
