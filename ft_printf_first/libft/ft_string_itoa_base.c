/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:31:55 by jinam             #+#    #+#             */
/*   Updated: 2022/08/02 21:17:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	_nbr_len(unsigned long nbr, unsigned long base_len)
{
	size_t	len;

	len = 1;
	while (nbr >= base_len)
	{
		nbr /= base_len;
		len ++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long nbr, char *base)
{
	size_t			nbr_len;
	char			*res;
	const size_t	base_len = ft_strlen(base);

	nbr_len = _nbr_len(nbr, base_len);
	res = malloc(sizeof(char) * (nbr_len + 1));
	if (!res)
		return ((void *) 0);
	res[nbr_len] = 0;
	if (nbr == 0)
		res[0] = '0';
	while (nbr)
	{
		res[nbr_len - 1] = base[nbr % base_len];
		nbr /= base_len;
		nbr_len --;
	}
	return (res);
}
