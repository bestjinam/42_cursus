/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_convert_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:22:08 by jinam             #+#    #+#             */
/*   Updated: 2022/08/06 22:05:15 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"
#include "ft_printf.h"

static int	_convert_base_print(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i++], 1) <= 0)
			return (-1);
	}
	free(str);
	return (i);
}

int	_convert_base(unsigned long nbr, char *base_from)
{
	char	*res1;

	res1 = ft_itoa_base(nbr, base_from);
	return (_convert_base_print(res1));
}
