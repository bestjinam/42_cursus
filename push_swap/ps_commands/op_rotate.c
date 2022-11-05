/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:54 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 15:10:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "op.h"

void	ra(t_stacks *stacks)
{
	add_rear(&stacks->stk_a, delete_front(&stacks->stk_a));
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	add_rear(&stacks->stk_b, delete_front(&stacks->stk_b));
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	ft_printf("rr\n");
}
