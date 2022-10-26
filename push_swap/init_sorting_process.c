/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:04 by jinam             #+#    #+#             */
/*   Updated: 2022/10/26 00:41:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle_map.h"
#include "push_swap.h"

static void	_three_sorting(t_stacks *stacks, t_min_max *min_max)
{
	const int	front = stacks->stack_a.front;
	const int	rear = (stacks->stack_b.rear + stacks->stack_b.cap - 1) \
					% stacks->stack_b.cap;
	const int	f_val = stacks->stack_a.buffer[front];
	const int	r_val = stacks->stack_a.buffer[rear - 1];

	if (f_val == min_max->min && r_val == min_max->max)
		return ;
	else if (f_val == min_max->min \
			&& r_val == min_max->mid)
	{
		rra(stacks);
		sa(stacks);
	}
	else if (f_val == min_max->mid && r_val == min_max->max)
		sa(stacks);
	else if (f_val == min_max->mid && r_val == min_max->min)
		rra(stacks);
	else if (f_val == min_max->max && r_val == min_max->mid)
		ra(stacks);
	else if (f_val == min_max->max && r_val == min_max->min)
	{
		sa(stacks);
		rra(stacks);
	}
}

static void	_four_sorting(t_stacks *stacks, t_min_max *min_max)
{
	int	n_mid_idx;
	int	n_min_idx;

	while (stacks->stack_a.buffer[stacks->stack_a.front] != min_max->min)
		ra(stacks);
	pb(stacks);
	n_mid_idx = stacks->buffer.len / 2 + stacks->buffer.len / 4 - 1;
	n_min_idx = stacks->buffer.len / 2 - 1;
	min_max->min = stacks->array[n_min_idx];
	min_max->mid = stacks->array[n_mid_idx];
	_three_sorting(stacks, min_max);
	pa(stacks);
}

static void	_five_sorting(t_stacks *stacks, t_min_max *min_max)
{
	int			i;
	int			b_rear;

	i = -1;
	while (++i < 5)
	{
		if (stacks->stack_a.buffer[stacks->stack_a.front] <= stacks->array[1])
			pb(stacks);
		else
			ra(stacks);
	}
	b_rear = (stacks->stack_b.rear + stacks->stack_b.cap - 1) \
			% stacks->stack_b.cap;
	if (stacks->stack_b.buffer[stacks->stack_b.front] < \
			stacks->stack_b.buffer[b_rear])
		sb(stacks);
	min_max->min = stacks->array[2];
	min_max->mid = stacks->array[3];
	_three_sorting(stacks, min_max);
	pa(stacks);
	pa(stacks);
}

void	merge_sorting_process(t_stacks *stacks)
{
	t_triangle_map *map;
	const int		size = stacks->buffer.len;
	int				i;
	int				j;


	map = triangle_map_create(size);
	stack_init(&stacks->commands, 1024);
	first_stack_a_move(stacks, map);
}

int	init_sorting(t_stacks *stacks)
{
	t_min_max	min_max;

	get_max_min(stacks->array, stacks->buffer.len, &min_max);
	if (stacks->buffer.len == 3)
		_three_sorting(stacks, &min_max);
	else if (stacks->buffer.len == 4)
		_four_sorting(stacks, &min_max);
	else if (stacks->buffer.len == 5)
		_five_sorting(stacks, &min_max);
	else
		merge_sorting_process(stacks);
	return (1);
}
