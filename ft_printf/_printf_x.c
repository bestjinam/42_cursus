/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/03 12:00:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_x(va_list ap)
{
	unsigned int	nbr;
	int				res2;

	nbr = va_arg(ap, unsigned int);
	res2 = _convert_base(nbr, "0123456789abcdef");
	if (res2 == -1)
		return (-1);
	return (res2);
}
