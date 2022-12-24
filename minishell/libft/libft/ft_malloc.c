/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:09:54 by jinam             #+#    #+#             */
/*   Updated: 2022/12/19 13:26:24 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_malloc(size_t size)
{
	void	*res;

	res = ft_calloc(1, size);
	if (!res)
	{
		perror("malloc");
		exit(1);
	}
	return (res);
}
