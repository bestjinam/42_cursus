/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:02:38 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/10/22 23:04:39 by ggul_jam         ###   ########.fr       */
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
