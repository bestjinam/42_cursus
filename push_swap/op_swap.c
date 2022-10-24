/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:04 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 14:39:06 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(stack_a);
	tmp2 = delete_front(stack_a);
	add_front(stack_a, tmp1);
	add_front(stack_a, tmp2);
}

void	sb(t_stack *stack_b)
{
	int	tmp1;
	int	tmp2;

	tmp1 = delete_front(stack_b);
	tmp2 = delete_front(stack_b);
	add_front(stack_b, tmp1);
	add_front(stack_b, tmp2);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
