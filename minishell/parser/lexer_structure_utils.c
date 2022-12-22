/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_structure_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:58:17 by jinam             #+#    #+#             */
/*   Updated: 2022/12/22 21:05:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "lexer.h"

t_cmd_node	*cmd_node_new(char *data, int type)
{
	t_cmd_node	*res;

	res = ft_malloc(sizeof(t_cmd_node));
	res->data = data;
	res->type = type;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	cmd_node_add_back(t_cmd_list *lst, t_cmd_node *n)
{
	t_cmd_node	*curr;

	if (!lst->head)
	{
		lst->head = n;
		lst->curr = n;
	}
	else
		lst->tail->next = n;
	lst->tail = n;
	lst->len ++;
}

t_cmd_node	*cmd_node_find(t_cmd_list *lst, char *data)
{
	t_cmd_node	*curr;

	curr = lst->head;
	while (curr)
	{
		if (curr->data && ft_strncmp(curr->data, data, ft_strlen(data) + 1) == 0)
			break ;
		curr = curr->next;
	}
	return (curr);
}

void	cmd_node_delete(t_cmd_list *lst, char *data)
{
	t_cmd_node	*curr;

	curr = lst->head;
	while (curr)
	{
		if (ft_strncmp(curr->data, data, ft_strlen(data) + 1) == 0)
		{
			if (curr->prev == NULL)
				lst->head = curr->next; 
			else
				curr->prev->next = curr->next;
			free(curr->data);
			free(curr);
			break ;
		}
		curr = curr->next;
	}
	lst->len --;
}
