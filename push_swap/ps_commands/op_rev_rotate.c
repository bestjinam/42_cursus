/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:39 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 15:10:07 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	rra(t_stacks *stacks)
{
	add_front(&stacks->stk_a, delete_rear(&stacks->stk_a));
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	add_front(&stacks->stk_b, delete_rear(&stacks->stk_b));
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_printf("rrr\n");
}
