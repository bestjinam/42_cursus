/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_pre_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:52:39 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 20:04:20 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_sorting.h"
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

void	get_max_min(int *arr, int size, t_min_max *min_max)
{
	min_max->min = arr[0];
	min_max->mid = arr[size / 2];
	min_max->max = arr[size - 1];
}
