/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_conquering_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:43:29 by jinam             #+#    #+#             */
/*   Updated: 2022/10/28 07:17:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*get_cur_stk(t_stacks *stks, int opt)
{
	if (opt == 0)
		return (&stks->stk_a);
	else
		return (&stks->stk_b);
}

t_stack	*get_opposit_stk(t_stacks *stks, int opt)
{
	if (opt == 0)
		return (&stks->stk_b);
	else 
		return (&stks->stk_a);
}

long	get_max_int(long n1, long n2, long n3)
{
	long	max;

	max = n1;		
	if (max < n2)
		max = n2;
	if (max < n3)
		max = n3;
	return (max);
}

long	get_min_int(long n1, long n2, long n3)
{
	long	min;

	min = n1;		
	if (min > n2)
		min = n2;
	if (min > n3)
		min = n3;
	return (min);
}

