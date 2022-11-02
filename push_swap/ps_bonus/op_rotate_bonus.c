/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:54 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 18:00:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_bonus.h"

void	ra(t_stacks *stacks)
{
	add_rear(&stacks->stk_a, delete_front(&stacks->stk_a));
}

void	rb(t_stacks *stacks)
{
	add_rear(&stacks->stk_b, delete_front(&stacks->stk_b));
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
