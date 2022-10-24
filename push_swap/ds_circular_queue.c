/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_circular_queue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:18 by jinam             #+#    #+#             */
/*   Updated: 2022/10/24 22:24:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->front == stack->rear);
}

void	add_rear(t_stack *stack, int data)
{
	stack->buffer[stack->rear] = data;
	stack->rear = (stack->rear + 1) % stack->cap;
}

void	add_front(t_stack *stack, int data)
{
	if (stack->front == 0)
		stack->front = stack->cap - 1;
	else
		stack->front = stack->front - 1;
	stack->buffer[stack->front] = data;
}

int	delete_rear(t_stack *stack)
{
	if (!is_empty(stack))
	{
		if (stack->rear == 0)
			stack->rear = stack->cap - 1;
		else
			stack->rear --;
		return (stack->buffer[stack->rear]);
	}
	return (-1);
}

int	delete_front(t_stack *stack)
{
	int	tmp;

	if (!is_empty(stack))
	{
		tmp = stack->buffer[stack->front];
		stack->front = (stack->front + 1) % stack->cap;
		return (tmp);
	}
	return (-1);
}
