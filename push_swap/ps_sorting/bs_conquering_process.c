/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_conquering_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:40:09 by jinam             #+#    #+#             */
/*   Updated: 2022/11/03 17:44:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_sorting.h"

void	push_one_third(t_stacks *stks, int *map_info, t_triangle_map *map)
{
	int			i;
	const int	opt = (map->depth - map_info[0]) % 2;
	const int	cnt = calculate_len(map, map_info[1], map_info[2] / 3);

	i = -1;
	while (++i < cnt)
	{
		if (opt == 0)
			pa(stks);
		else
			pb(stks);
	}
}

void	merge_triangles(t_stacks *stks, int p_idx, t_triangle_map *map, \
						int direction)
{
	const int	mold = map->mold[p_idx];
	int			val[3];

	val[0] = map->val[p_idx] / 3;
	val[1] = map->val[p_idx] / 3 + map->val[p_idx] % 3;
	val[2] = map->val[p_idx] / 3;
	while (val[0] || val[1] || val[2])
	{
		if (get_stk_len(get_opposit_stk(stks, direction)) == 1)
		{
			val[2] = 0;
			val[1] = 1;
		}
		if (mold == UP)
			val[making_up(stks, val, direction)]--;
		else
			val[making_down(stks, val, direction)]--;
	}
}
/*
 * map_info[0] = depth
 * map_info[1] = start_idx;
 * map_info[2] = size;
 */

void	conquering_processing(t_stacks *stks, t_triangle_map *map)
{
	int	map_info[3];
	int	p_idx;

	map_info[0] = map->depth + 1;
	while (--map_info[0] > 0)
	{
		calculate_idx_and_size(map_info[0], &map_info[1], &map_info[2]);
		push_one_third(stks, map_info, map);
		p_idx = map_info[1] - map_info[2] / 3 - 1;
		while (++p_idx < map_info[1])
		{
			merge_triangles(stks, p_idx, map, (map->depth - map_info[0]) % 2);
		}
	}
	if (map->depth % 2 == 0)
	{
		while (!is_empty(&stks->stk_b))
			pa(stks);
	}
}
