/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:26 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 22:57:35 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b) == 1)
		return ;
	add_front(stack_a, delete_front(stack_b));
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	if (is_empty(stack_a) == 1)
		return ;
	add_front(stack_b, delete_front(stack_a));
}
