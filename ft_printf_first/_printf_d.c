/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/06 19:22:56 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_nbr_len(long nbr)
{
	int	i;

	i = 0;
	nbr = (nbr * ((nbr > 0) - (nbr < 0)));
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i ++;
	}
	return (i);
}

int	_printf_d(t_format *format, va_list ap)
{
	long		nbr;
	int			nbr_len;
	const char	*base = "0123456789";

	nbr = (long) va_arg(ap, int);
	nbr_len = _nbr_len(nbr);
	if ((format->flags & 040) == 040 && format->precision == 0 && nbr == 0)
		return (_printf_d_zero_precision_zero_process(format));
	if ((format->flags & 02) == 02)
		return (_printf_d_minus_process(format, nbr, nbr_len, (char *) base));
	else if ((format->flags & 020) == 020)
		return (_printf_d_zero_process(format, nbr, nbr_len, (char *) base));
	else
		return (_printf_d_plain_process(format, nbr, nbr_len, (char *) base));
}
