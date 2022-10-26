/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:04 by jinam             #+#    #+#             */
/*   Updated: 2022/10/26 00:36:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(&stacks->stack_a);
	tmp2 = delete_front(&stacks->stack_a);
	add_front(&stacks->stack_a, tmp1);
	add_front(&stacks->stack_a, tmp2);
	ft_putstr("sa\n");
}

void	sb(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(&stacks->stack_b);
	tmp2 = delete_front(&stacks->stack_b);
	add_front(&stacks->stack_b, tmp1);
	add_front(&stacks->stack_b, tmp2);
	ft_putstr("sb\n");
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_putstr("ss\n");
}
