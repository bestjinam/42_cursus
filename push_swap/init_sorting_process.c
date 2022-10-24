/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:04 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 22:53:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_three_sorting(t_stacks *stacks, t_min_max *min_max)
{
	const int	front = stacks->stack_a.front;
	int			rear;

	rear = stacks->stack_a.rear - 1;
	if (stacks->stack_a.rear == 0)
		rear = stacks->stack_a.cap - 1;
	if (stacks->stack_a.buffer[front] == min_max->min \
			&& stacks->stack_a.buffer[rear] == min_max->max)
		return ;
	else if (stacks->stack_a.buffer[front] == min_max->min \
			&& stacks->stack_a.buffer[rear] == min_max->mid)
	{
		rra(&stacks->stack_a);
		sa(&stacks->stack_a);
	}
	else if (stacks->stack_a.buffer[front] == min_max->mid \
			&& stacks->stack_a.buffer[rear] == min_max->max)
		sa(&stacks->stack_a);
	else if (stacks->stack_a.buffer[front] == min_max->mid \
			&& stacks->stack_a.buffer[rear] == min_max->min)
		rra(&stacks->stack_a);
	else if (stacks->stack_a.buffer[front] == min_max->max \
			&& stacks->stack_a.buffer[rear] == min_max->mid)
		ra(&stacks->stack_a);
	else if (stacks->stack_a.buffer[front] == min_max->max \
			&& stacks->stack_a.buffer[rear] == min_max->min)
	{
		sa(&stacks->stack_a);
		rra(&stacks->stack_a);
	}
}

static void	_four_sorting(t_stacks *stacks, t_min_max *min_max)
{
	int	n_mid_idx;
	int	n_min_idx;

	while (stacks->stack_a.buffer[stacks->stack_a.front] != min_max->min)
		ra(&stacks->stack_a);
	pb(&stacks->stack_b, &stacks->stack_a);
	n_mid_idx = stacks->buffer.len / 2 + stacks->buffer.len/4 - 1;
	n_min_idx = stacks->buffer.len / 2 - 1;
	min_max->min = stacks->array[n_min_idx];
	min_max->mid = stacks->array[n_mid_idx];
	_three_sorting(stacks, min_max);
	pa(&stacks->stack_a, &stacks->stack_b);
}



static void	_five_sorting(t_stacks *stacks, t_min_max *min_max)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (stacks->stack_a.buffer[stacks->stack_a.front] <= stacks->array[1])
			pb(&stacks->stack_b, &stacks->stack_a);
		else
			ra(&stacks->stack_a);
	}
	if (stacks->stack_b.buffer[stacks->stack_b.front] > stacks->stack_b.buffer[stacks->stack_b.rear])
		sb(&stacks->stack_b);
	min_max->min = stacks->array[2];
	min_max->mid = stacks->array[3];
	_three_sorting(stacks, min_max);
	pa(&stacks->stack_a, &stacks->stack_b);
	pa(&stacks->stack_a, &stacks->stack_b);
}

void	merge_sorting_process(t_stacks *stacks)
{

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
