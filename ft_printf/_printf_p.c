/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by jinam             #+#    #+#             */
/*   Updated: 2022/08/03 01:58:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	_printf_p(va_list ap)
{
	unsigned long	pointer;
	int				res1;
	int				res2;
	int				idx;

	pointer = (unsigned long) va_arg(ap, void *);
	idx = 0;
	res1 = 0;
	while (idx < 2)
	{
		if (write(1, &"0x"[idx], 1) == -1)
			return (-1);
		else
			res1 ++;
		idx ++;
	}
	res2 = _convert_base(pointer, "0123456789abcdef");
	if (res2 == -1)
		return (-1);
	return (res1 + res2);
}
