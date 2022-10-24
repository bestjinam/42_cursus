/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:26 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 14:38:30 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b))
		return ;
	add_front(stack_a, delete_front(stack_b));
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a))
		return ;
	add_front(stack_b, delete_front(stack_a));
}
