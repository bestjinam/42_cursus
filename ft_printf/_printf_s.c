/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:11:39 by jinam             #+#    #+#             */
/*   Updated: 2022/08/03 10:23:56 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_s(va_list ap)
{
	char	*str;
	int		tmp;
	int		res;

	str = va_arg(ap, char *);
	res = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		tmp = write(1, str, 1);
		if (!tmp)
			return (-1);
		else
			res += tmp;
		str ++;
	}
	return (res);
}
