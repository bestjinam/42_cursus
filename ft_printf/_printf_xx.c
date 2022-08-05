/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/04 22:42:20 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_xx(t_format *format, va_list ap)
{
	unsigned int	nbr;
	int				res2;
	(void) format;

	nbr = va_arg(ap, unsigned int);
	res2 = _convert_base(nbr, "0123456789ABCDEF");
	if (res2 == -1)
		return (-1);
	return (res2);
}
