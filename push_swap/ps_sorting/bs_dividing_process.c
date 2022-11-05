/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_dividing_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:57:40 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 15:58:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sorting.h"

int	calculate_len(t_triangle_map *map, int m_idx, int size)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = -1;
	while (++i < size)
	{
		cnt += map->val[m_idx + i];
	}
	return (cnt);
}

void	calculate_idx_and_size(int depth, int *m_idx, int *size)
{
	int	i;

	*m_idx = 0;
	*size = 1;
	i = -1;
	while (++i < depth)
	{
		*m_idx = *m_idx * 3 + 1;
		*size *= 3;
	}
}

int	calculate_depth(int size)
{
	int	i;

	i = 0;
	while (size > 2)
	{
		size /= 3;
		i ++;
	}
	return (i);
}

void	push_tri_to_b(t_stacks *stacks, int size, int opt)
{
	if (size == 1)
		pb(stacks);
	if (size == 2)
	{
		two_elements_sorting_a(stacks, opt);
		pb(stacks);
		pb(stacks);
	}
	else if (size == 3)
		three_elements_sorting_a(stacks, opt);
	else if (size == 4)
		four_elements_sorting_a(stacks, opt);
	else if (size == 5)
		five_elements_sorting_a(stacks, opt);
}

void	dividing_processing(t_stacks *stacks, t_triangle_map *map)
{
	int	i;
	int	m_idx;
	int	size;

	i = -1;
	calculate_idx_and_size(map->depth, &m_idx, &size);
	while (++i < size)
	{
		if (map->mold[m_idx + i] == UP)
			push_tri_to_b(stacks, map->val[m_idx + i], UP);
		else
			push_tri_to_b(stacks, map->val[m_idx + i], DOWN);
	}
}
