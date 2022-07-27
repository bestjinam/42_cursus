/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:08:43 by jinam             #+#    #+#             */
/*   Updated: 2022/07/27 12:09:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*_gnl_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	if (!s1 & !s2)
		return (0);
	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	if (s2 < s1)
	{
		i = n;
		while (i > 0)
		{
			tmp_s1[i - 1] = tmp_s2[i - 1];
			i --;
		}
	}
	else if (s2 > s1)
	{
		i = -1;
		while (++i < n)
			tmp_s1[i] = tmp_s2[i];
	}
	return (s1);
}
