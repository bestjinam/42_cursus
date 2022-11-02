/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:04 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 16:49:35 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_bonus.h"

void	sa(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(&stacks->stk_a);
	tmp2 = delete_front(&stacks->stk_a);
	add_front(&stacks->stk_a, tmp1);
	add_front(&stacks->stk_a, tmp2);
}

void	sb(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(&stacks->stk_b);
	tmp2 = delete_front(&stacks->stk_b);
	add_front(&stacks->stk_b, tmp1);
	add_front(&stacks->stk_b, tmp2);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
