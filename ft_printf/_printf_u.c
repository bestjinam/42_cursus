/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/03 10:37:22 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	_printf_u(va_list ap)
{
	long	nbr;
	int		res2;

	nbr = (unsigned long) va_arg(ap, unsigned int);
	res2 = _convert_base(nbr, "0123456789");
	if (res2 == -1)
		return (-1);
	return (res2);
}
