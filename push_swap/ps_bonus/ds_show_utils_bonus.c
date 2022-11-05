/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_show_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:22:37 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 17:59:20 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ds_bonus.h"

int	get_stk_len(t_stack *stk)
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
