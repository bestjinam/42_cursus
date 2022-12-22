/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_structure_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:36:29 by jinam             #+#    #+#             */
/*   Updated: 2022/12/22 17:02:08 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser.h"
#include <stdlib.h>
#include "../libft/libft/libft.h"

t_list	*cmd_data_new(char *data, int type)
{
	t_cmd_data	*res_data;

	res_data = ft_malloc(sizeof(t_cmd_data));
	res_data->string = data;
	res_data->type = type;
	return (ft_lstnew(res_data));
}

t_cmd_tnode	*tnode_new(t_list *str, t_list *re, int type)
{
	t_cmd_tnode	*res;

	res = ft_malloc(sizeof(t_cmd_tnode));
	res->l_node = NULL;
	res->r_node = NULL;
	res->redirection = re;
	res->string = str;
	res->type = type;
	return (res);
}

t_cmd_tnode	*tnode_add(t_cmd_tnode **node, t_cmd_tnode *n)
{
	if (!*node)
		*node = n;
	/* error 
	if ((*node)->l_node && (*node)->r_node)
		return (NULL);*/
	else if (!(*node)->l_node)
		(*node)->l_node = n;
	else if (!(*node)->r_node)
		(*node)->r_node = n;
	else
		tnode_get_rlast(*node)->r_node = n;
	return (*node);
}

t_cmd_tnode	*tnode_get_rlast(t_cmd_tnode *root)
{
	/*
	if (!root->r_node)
		syntax error!
	*/
	if (!root->r_node || \
			root->r_node->type == STRING || root->r_node->type == BR_OPEN)
		return (root);
	return (tnode_get_rlast(root->r_node));
}

void		tree_delete(t_cmd_tnode *root)
{
	if (!root)
		return ;
	tree_delete(root->r_node);
	tree_delete(root->l_node);
	ft_lstclear(&root->redirection, free);
	ft_lstclear(&root->string, free);
	free(root);
}


