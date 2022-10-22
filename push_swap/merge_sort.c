/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _merge_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:52:39 by jinam             #+#    #+#             */
/*   Updated: 2022/10/21 19:59:12 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

void	merge(int start, int mid, int end, t_stacks *stacks)
{
	int	i;
	int	j;
	int	k;
	int	*dest;

	i = start;
	j = mid + 1;
	k = 0;
	dest = malloc(sizeof(int) * (end - start + 1));
	if (!dest)
		return ;
	while (i <= mid && j <= end)
	{
		if (stacks->array[i] <= stacks->array[j])
			dest[k] = stacks->array[i++];
		else
			dest[k] = stacks->array[j++];
		k ++;
	}
	while (i <= mid)
		dest[k ++] = stacks->array[i++];
	while (j <= end)
		dest[k ++] = stacks->array[j++];
	ft_memcpy(&stacks->array[start], dest, (end - start + 1) * sizeof(int));
	free(dest);
}

void	merge_sort(int left, int right, t_stacks *stacks)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(left, mid, stacks);
		merge_sort(mid + 1, right, stacks);
		merge(left, mid, right, stacks);
	}
}
