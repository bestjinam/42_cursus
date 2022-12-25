/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:16:24 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 20:23:24 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ms_lexer_structure.h"

t_cmd_node	*cnode_new(char *data, int type)
{
	t_cmd_node	*res;

	res = ft_malloc(sizeof(t_cmd_node));
	res->data = data;
	res->type = type;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	cnode_add_back(t_cmd_list *lst, t_cmd_node *n)
{
	if (!lst->head)
		lst->head = n;
	else
		lst->tail->next = n;
	lst->tail = n;
	lst->len ++;
}

t_cmd_node	*cnode_find(t_cmd_list *lst, char *data)
{
	t_cmd_node	*curr;
	int			cmp_result;

	curr = lst->head;
	while (curr)
	{
		cmp_result = ft_strncmp(curr->data, data, ft_strlen(data) + 1);
		if (curr->data && cmp_result == 0)
			break ;
		curr = curr->next;
	}
	return (curr);
}

void	cnode_delete(t_cmd_list *lst, char *data)
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
