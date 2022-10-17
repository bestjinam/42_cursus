/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:09:17 by jinam             #+#    #+#             */
/*   Updated: 2022/10/17 21:29:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "push_swap.h"

int	stack_init(t_int_stack *tmp, int cap)
{
	tmp->buffer = malloc(sizeof(int) * cap);
	if (!tmp->buffer)
		return (-1);
	tmp->len = 0;
	tmp->cap = cap;
	tmp->front = -1;
	tmp->rear = -1;
	return (1);
}

int	stack_append(t_int_stack *tmp, int c)
{
	size_t	i;
	int		*cpy_list;
	i = -1;
	if (tmp->len == tmp->cap)
	{
		tmp->cap *= 2;
		cpy_list = malloc(sizeof(int) * tmp->cap);
		if (!cpy_list)
			return (-1);
		ft_memcpy(cpy_list, tmp->buffer, tmp->len);
		free(tmp->buffer);
		tmp->buffer = cpy_list;
	}
	tmp->buffer[(tmp->len)++] = c;
	return (1);
}

int	stack_delete(t_int_stack *temp)
{
	if (!temp)
		return (-1);
	free(temp->buffer);
	temp->buffer = (void *) 0;
	return (1);
}
