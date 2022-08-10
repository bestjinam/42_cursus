/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:31:55 by jinam             #+#    #+#             */
/*   Updated: 2022/08/11 01:18:02 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	_nbr_len(long long nbr, size_t l)
{
	size_t	len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= l;
		len ++;
	}
	return (len);
}

char	*ft_itoa_base(long long n, char *base)
{
	long long		nbr;
	size_t			nbr_len;
	char			*res;
	const size_t	base_len = ft_strlen(base);

	nbr = (long long) n;
	nbr = nbr * ((nbr > 0) - (nbr < 0));
	nbr_len = (n < 0) + _nbr_len(nbr, base_len);
	res = malloc(sizeof(char) * (nbr_len + 1));
	if (!res)
		return ((void *) 0);
	res[nbr_len] = 0;
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (nbr_len > 0)
	{
		res[nbr_len - 1] = base[nbr % base_len];
		nbr /= base_len;
		nbr_len --;
	}
	return (res);
}
