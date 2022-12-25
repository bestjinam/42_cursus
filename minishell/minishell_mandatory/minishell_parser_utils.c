/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:28:02 by jinam             #+#    #+#             */
/*   Updated: 2022/12/25 18:54:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_mandatory.h"

int	pu_is_redirect(int type)
{
	return (type == RE_IN || type == RE_OUT || type == RE_APPEND \
			|| type == RE_HEREDOC);
}

int	pu_is_operator(t_cmd_node *node)
{
	return (node->type == PIPE || node->type == AND || node->type == OR);
}

t_cmd_tnode	*pu_make_cmd_tnode(t_cmd_tree *t)
{
	t_cmd_tnode	*res;

	res = ft_malloc(sizeof(t_cmd_tnode));
	while (t->curr && (t->curr->type == STRING \
				|| pu_is_redirect(t->curr->type)))
	{
		if (t->curr->type == STRING)
			ft_lstadd_back(&res->string, \
					cmd_data_new(t->curr->data, t->curr->type));
		else
		{
			if (!t->curr->next || t->curr->next->type != STRING)
			{
				tree_delete(res);
				return (NULL);
			}
			ft_lstadd_back(&res->redirection, \
					cmd_data_new(t->curr->next->data, t->curr->type));
			t->curr = t->curr->next;
		}
		t->curr = t->curr->next;
	}
	return (res);
}

int	pu_br_redirect(t_cmd_tree *tree)
{	
	t_list	*tmp;

	while (tree->curr && pu_is_redirect(tree->curr->type))
	{
		tmp = cmd_data_new(tree->curr->next->data, tree->curr->type);
		ft_lstadd_back(&(tree->root)->redirection, tmp);
		if (!tree->curr->next || tree->curr->next->type != STRING)
			return (SYNTAX_ERROR);
		tree->curr = tree->curr->next->next;
	}
	return (SUCCESS);
}

int	ms_parser_and_or(t_cmd_tree *tree)
{
	t_cmd_tnode	*node;

	node = tnode_new(NULL, NULL, tree->curr->type);
	tnode_add(node, tree->root);
	tree->root = node;
	tree->curr = tree->curr->next;
	return (SUCCESS);
}
