/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_data_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:01:31 by jinam             #+#    #+#             */
/*   Updated: 2022/10/28 01:53:31 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int get_stk_len(t_stack *stk)
{
	return ((stk->rear - stk->front + stk->cap) % stk->cap);
}

int	show_front(t_stack *stack)
{
	return (stack->buffer[stack->front]);
}

int	show_rear(t_stack *stack)
{
	return (stack->buffer[(stack->rear + stack->cap - 1) % stack->cap]);
}

int	show_nxt_front(t_stack *stack)
{
	return (stack->buffer[(stack->front + 1) % stack->cap]);
}

int	show_value(t_stack *stack, int loc, int idx)
{
	if (loc == 0)
		return (stack->buffer[(stack->front + idx) % stack->cap]);
	else
		return (stack->buffer[(stack->rear + stack->cap - idx) % stack->cap]);
}
