/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_conquering.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:40:09 by jinam             #+#    #+#             */
/*   Updated: 2022/10/28 07:39:31 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "triangle_map.h"

void	push_one_third(t_stacks *stks, int *map_info,t_triangle_map *map)
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

int	making_up(t_stacks *stks, int *val, int opt)
{
	const t_op_ptr	op[4] = {rrb, pa, rra, pb};
	long			max;
	long			cmp_res[3];
	int				i;

	cmp_res[0] = show_rear(get_cur_stk(stks, opt));
	cmp_res[1] = show_front(get_opposit_stk(stks, opt));
	cmp_res[2] = show_rear(get_opposit_stk(stks, opt));
	i = -1;
	while (++i < 3)
	{
		if (val[i] == 0)
			cmp_res[i] = -2147483649;
	}
	max = get_max_int(cmp_res[0], cmp_res[1], cmp_res[2]);
	if (cmp_res[0] == max)
	{
		op[2 - opt * 2](stks);
		return (0);
	}
	else if (cmp_res[1] == max)
	{
		op[opt * 2 + 1](stks);
		return (1);
	}
	else
	{
		op[opt * 2](stks);
		op[opt * 2 + 1](stks);
		return (2);
	}
}

int	making_down(t_stacks *stks, int *val, int opt)
{
	const t_op_ptr	op[4] = {rrb, pa, rra, pb};
	long			min;
	long			cmp_res[3];
	int				i;

	i = -1;

	cmp_res[0] = show_rear(get_cur_stk(stks, opt));
	cmp_res[1] = show_front(get_opposit_stk(stks, opt));
	cmp_res[2] = show_rear(get_opposit_stk(stks, opt));

	while (++i < 3)
	{
		if (val[i] == 0)
			cmp_res[i] = 2147483648;
	}
	min = get_min_int(cmp_res[0], cmp_res[1], cmp_res[2]);
	if (cmp_res[0] == min)
	{
		op[2 - opt * 2](stks);
		return (0);
	}
	else if (cmp_res[1] == min)
	{
		op[opt * 2 + 1](stks);
		return (1);
	}
	else
	{
		op[opt * 2](stks);
		op[opt * 2 + 1](stks);
		return (2);
	}
}

void	merging_triangles(t_stacks *stks, int p_idx, t_triangle_map *map, int opt)
{

	const int	mold = map->mold[p_idx];
	int			val[3];

	val[0] = map->val[p_idx] / 3;
	val[1] = map->val[p_idx] / 3 + map->val[p_idx] % 3;
	val[2] = map->val[p_idx] / 3;
	while (val[0] || val[1] || val[2])
	{
		if (get_stk_len(get_opposit_stk(stks, opt)) == 1)
		{
			val[2] = 0;
			val[1] = 1;
		}
		if (mold == UP)
			val[making_up(stks, val, opt)] --;
		else
			val[making_down(stks, val, opt)] --;
	}
}

/*
 * map_info[0] = depth
 * map_info[1] = start_idx;
 * map_info[2] = size;
 */

void	conquering_processing(t_stacks *stks, t_triangle_map *map)
{
	int map_info[3];
	int i;
	int	p_idx;

	map_info[0] = map->depth + 1;
	while (--map_info[0] > 0)
	{
		calculate_idx_and_size(map_info[0], &map_info[1], &map_info[2]);
		push_one_third(stks, map_info, map);
		p_idx = map_info[1] - map_info[2] / 3 - 1;
		while (++p_idx < map_info[1])
		{
			merging_triangles(stks, p_idx, map, (map->depth - map_info[0]) % 2);	
		}
	}
	if (map->depth % 2 == 0)
	{
		while (!is_empty(&stks->stk_b))
			pa(stks);
	}
}
