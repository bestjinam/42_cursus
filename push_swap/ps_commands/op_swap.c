/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:04 by jinam             #+#    #+#             */
/*   Updated: 2022/10/31 15:11:27 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	sa(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(&stacks->stk_a);
	tmp2 = delete_front(&stacks->stk_a);
	add_front(&stacks->stk_a, tmp1);
	add_front(&stacks->stk_a, tmp2);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(&stacks->stk_b);
	tmp2 = delete_front(&stacks->stk_b);
	add_front(&stacks->stk_b, tmp1);
	add_front(&stacks->stk_b, tmp2);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_printf("ss\n");
}
