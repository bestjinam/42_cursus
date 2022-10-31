/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_dividing_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:19 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 15:56:29 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sorting.h"

void	two_elements_sorting_a(t_stacks *stacks, int opt)
{
	if (opt == 0)
	{
		if (show_front(&stacks->stk_a) < show_nxt_front(&stacks->stk_a))
			sa(stacks);
	}
	else
	{
		if (show_front(&stacks->stk_a) > show_nxt_front(&stacks->stk_a))
			sa(stacks);
	}
}

void	three_elements_sorting_a(t_stacks *stks, int opt)
{
	int		i;
	t_stack	*stk_a;

	i = -1;
	stk_a = &stks->stk_a;
	two_elements_sorting_a(stks, opt);
	while (opt == 0 && (++i < 2 && show_front(stk_a) > show_rear(stk_a)))
		pb(stks);
	while (opt == 1 && (++i < 2 && show_front(stk_a) < show_rear(stk_a)))
		pb(stks);
	rra(stks);
	pb(stks);
	while (++i <= 2)
		pb(stks);
}

static void	_rev_three_tri_to_b(t_stacks *stks, int opt)
{
	three_elements_sorting_a(stks, opt);
	rb(stks);
	rb(stks);
	rb(stks);
}

void	four_elements_sorting_a(t_stacks *stks, int opt)
{
	int	val[3];

	val[0] = 1;
	val[1] = 2;
	val[2] = 1;
	pb(stks);
	rb(stks);
	two_elements_sorting_a(stks, opt);
	while (val[0] || val[1] || val[2])
	{
		if (get_stk_len(&stks->stk_a) == 1)
		{
			val[2] = 0;
			val[1] = 1;
		}
		if (opt == 0)
			val[making_up(stks, val, 1)]--;
		else
			val[making_down(stks, val, 1)]--;
	}
}

void	five_elements_sorting_a(t_stacks *stks, int opt)
{
	int	i;
	int	j;

	_rev_three_tri_to_b(stks, opt);
	two_elements_sorting_a(stks, opt);
	i = 0;
	j = 0;
	while (i < 2 && j < 3)
	{
		if ((opt == 0 && show_front(&stks->stk_a) < show_rear(&stks->stk_b)) \
			|| (opt == 1 && show_front(&stks->stk_a) > show_rear(&stks->stk_b)))
		{
			rrb(stks);
			j ++;
		}
		else
		{
			pb(stks);
			i ++;
		}
	}
	while (i++ < 2)
		pb(stks);
	while (j++ < 3)
		rrb(stks);
}
