/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:21:56 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 15:38:45 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sorting.h"

static void	_two_sorting(t_stacks *stks)
{
	if (show_front(&stks->stk_a) > show_nxt_front(&stks->stk_a))
		sa(stks);
}

static void	_three_sorting(t_stacks *stacks, t_min_max *min_max)
{
	const int	front = stacks->stk_a.front;
	const int	f_val = stacks->stk_a.buffer[front];
	const int	r_val = show_value(&stacks->stk_a, 1, 1);

	if (f_val == min_max->min && r_val == min_max->max)
		return ;
	else if (f_val == min_max->min && r_val == min_max->mid)
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

	while (stacks->stk_a.buffer[stacks->stk_a.front] != min_max->min)
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
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (stacks->stk_a.buffer[stacks->stk_a.front] <= stacks->array[1])
			pb(stacks);
		else
			ra(stacks);
	}
	if (show_front(&stacks->stk_b) < show_rear(&stacks->stk_b))
		sb(stacks);
	min_max->min = stacks->array[2];
	min_max->mid = stacks->array[3];
	_three_sorting(stacks, min_max);
	pa(stacks);
	pa(stacks);
}

void	small_sorting_process(t_stacks *stks)
{
	const int	len = stks->buffer.len;
	t_min_max	min_max;

	get_max_min(stks->array, stks->buffer.len, &min_max);
	if (len == 2)
		_two_sorting(stks);
	else if (len == 3)
		_three_sorting(stks, &min_max);
	else if (len == 4)
		_four_sorting(stks, &min_max);
	else
		_five_sorting(stks, &min_max);
}
