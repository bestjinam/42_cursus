/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:54 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 14:38:56 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	add_rear(stack_a, delete_front(stack_a));
}

void	rb(t_stack *stack_b)
{
	add_rear(stack_b, delete_front(stack_b));
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
