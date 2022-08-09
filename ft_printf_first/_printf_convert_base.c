/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_convert_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:22:08 by jinam             #+#    #+#             */
/*   Updated: 2022/08/08 21:01:05 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"
#include "ft_printf.h"

static int	_convert_base_print(char *str)
{
	int	res;

	res = 0;
	res = write(1, str, ft_strlen(str));
	free(str);
	return (res);
}

int	_convert_base(unsigned long nbr, char *base_from)
{
	char	*res1;

	res1 = ft_itoa_base(nbr, base_from);
	if (!res1)
		return (-1);
	return (_convert_base_print(res1));
}
