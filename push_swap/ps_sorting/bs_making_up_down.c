/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_making_up_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:52:53 by jinam             #+#    #+#             */
/*   Updated: 2022/11/03 17:43:09 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_sorting.h"

static void	_get_three_values(long *values, t_stacks *stks, int direction)
{
	values[0] = show_rear(get_cur_stk(stks, direction));
	values[1] = show_front(get_opposit_stk(stks, direction));
	values[2] = show_rear(get_opposit_stk(stks, direction));
}

static void	_fill_zero_values(int *sizes, long *values, int mold)
{
	int		i;
	long	tmp;

	if (mold == UP)
		tmp = -2147483649;
	else
		tmp = 2147483648;
	i = -1;
	while (++i < 3)
	{
		if (sizes[i] == 0)
			values[i] = tmp;
	}
}

int	making_up(t_stacks *stks, int *val, int direction)
{
	const t_op_ptr	operator[4] = {rrb, pa, rra, pb};
	long			max;
	long			cmp_res[3];

	_get_three_values(cmp_res, stks, direction);
	_fill_zero_values(val, cmp_res, UP);
	max = get_max_int(cmp_res[0], cmp_res[1], cmp_res[2]);
	if (cmp_res[0] == max)
	{
		operator[2 - direction * 2](stks);
		return (0);
	}
	else if (cmp_res[1] == max)
	{
		operator[direction * 2 + 1](stks);
		return (1);
	}
	else
	{
		operator[direction * 2](stks);
		operator[direction * 2 + 1](stks);
		return (2);
	}
}

int	making_down(t_stacks *stks, int *val, int direction)
{
	const t_op_ptr	operator[4] = {rrb, pa, rra, pb};
	long			min;
	long			cmp_res[3];

	_get_three_values(cmp_res, stks, direction);
	_fill_zero_values(val, cmp_res, DOWN);
	min = get_min_int(cmp_res[0], cmp_res[1], cmp_res[2]);
	if (cmp_res[0] == min)
	{
		operator[2 - direction * 2](stks);
		return (0);
	}
	else if (cmp_res[1] == min)
	{
		operator[direction * 2 + 1](stks);
		return (1);
	}
	else
	{
		operator[direction * 2](stks);
		operator[direction * 2 + 1](stks);
		return (2);
	}
}
