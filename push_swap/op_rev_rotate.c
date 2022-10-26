/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:39 by jinam             #+#    #+#             */
/*   Updated: 2022/10/26 00:33:01 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	add_front(&stacks->stack_a, delete_rear(&stacks->stack_a));
	ft_putstr("rra\n");
}

void	rrb(t_stacks *stacks)
{
	add_front(&stacks->stack_b, delete_rear(&stacks->stack_b));
	ft_putstr("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_putstr("rrr\n");
}
