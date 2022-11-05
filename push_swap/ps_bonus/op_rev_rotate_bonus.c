/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:39 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 16:49:04 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_bonus.h"

void	rra(t_stacks *stacks)
{
	add_front(&stacks->stk_a, delete_rear(&stacks->stk_a));
}

void	rrb(t_stacks *stacks)
{
	add_front(&stacks->stk_b, delete_rear(&stacks->stk_b));
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
