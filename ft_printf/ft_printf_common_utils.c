/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_common_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:05:42 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/10 23:15:29 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	_printf_width(t_temp_str *t_str, int width, char c)
{
	if (width == 0)
		return ;
	while (width)
	{
		ft_c_append(t_str, c);
		width --;
	}
}

int	_pf_nbr_len(long long nbr, size_t len)
{
	int	i;

	i = 0;
	nbr = nbr * ((nbr > 0) - (nbr < 0));
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= len;
		i ++;
	}
	return (i);
}
