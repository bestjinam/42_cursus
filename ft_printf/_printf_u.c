/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/04 22:42:05 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_u(t_format *format, va_list ap)
{
	long	nbr;
	(void) format;
	int		res2;

	nbr = (unsigned long) va_arg(ap, unsigned int);
	res2 = _convert_base(nbr, "0123456789");
	if (res2 == -1)
		return (-1);
	return (res2);
}
