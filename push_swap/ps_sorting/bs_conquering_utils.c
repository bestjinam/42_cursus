/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_conquering_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:43:29 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 21:56:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_sorting.h"

long	get_max_int(long n1, long n2, long n3)
{
	long	max;

	max = n1;
	if (max < n2)
		max = n2;
	if (max < n3)
		max = n3;
	return (max);
}

long	get_min_int(long n1, long n2, long n3)
{
	long	min;

	min = n1;
	if (min > n2)
		min = n2;
	if (min > n3)
		min = n3;
	return (min);
}
