/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:09:17 by jinam             #+#    #+#             */
/*   Updated: 2022/10/28 13:20:01 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "push_swap.h"

int	stack_init(t_stack *tmp, int cap)
{
	tmp->buffer = malloc(sizeof(int) * (cap + 1));
	if (!tmp->buffer)
		return (-1);
	tmp->len = 0;
	tmp->cap = cap + 1;
	tmp->front = 0;
	tmp->rear = 0;
	return (1);
}

int	stack_append(t_stack *tmp, int c)
{
	int		*cpy_list;

	if (tmp->len == tmp->cap)
	{
		tmp->cap *= 2;
		cpy_list = malloc(sizeof(int) * tmp->cap);
		if (!cpy_list)
			return (-1);
		ft_memcpy(cpy_list, tmp->buffer, sizeof(int) * tmp->len);
		free(tmp->buffer);
		tmp->buffer = cpy_list;
	}
	tmp->buffer[(tmp->len)++] = c;
	tmp->rear = tmp->len;
	return (1);
}

int	stack_delete(t_stack *temp)
{
	if (!temp)
		return (-1);
	free(temp->buffer);
	temp->buffer = (void *) 0;
	return (1);
}
