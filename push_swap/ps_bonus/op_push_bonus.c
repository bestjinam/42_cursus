/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:26 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 16:48:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_bonus.h"

void	pa(t_stacks *stacks)
{
	if (is_empty(&stacks->stk_b) == 1)
		return ;
	add_front(&stacks->stk_a, delete_front(&stacks->stk_b));
}

void	pb(t_stacks *stacks)
{
	if (is_empty(&stacks->stk_a) == 1)
		return ;
	add_front(&stacks->stk_b, delete_front(&stacks->stk_a));
}
