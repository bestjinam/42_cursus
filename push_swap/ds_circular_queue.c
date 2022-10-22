/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_circular_queue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:02:32 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/10/22 19:21:30 by ggul_jam         ###   ########.fr       */
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
