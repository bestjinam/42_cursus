/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:28:02 by jinam             #+#    #+#             */
/*   Updated: 2023/01/19 16:53:43 by jinam            ###   ########.fr       */
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
	t_list		*l;

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
				return (tree_delete(res));
			ft_lstadd_back(&res->redirection, \
					cmd_data_new(t->curr->next->data, t->curr->type));
			l = ft_lstlast(res->redirection);
			if (t->curr->type == RE_HEREDOC)
				ms_heredoc(&g_info.env_list, l->content);
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
		if (tree->curr->type == RE_HEREDOC)
			ms_heredoc(&g_info.env_list, tmp->content);
		tree->curr = tree->curr->next->next;
	}
	return (SUCCESS);
}

int	ms_parser_and_or(t_cmd_tree *tree)
{
	t_cmd_tnode	*node;
	const int	type = tree->curr->type;

	if (!tree->curr->next || (tree->curr->next->type != STRING \
							&& !pu_is_redirect(tree->curr->next->type)))
		return (SYNTAX_ERROR);
	node = tnode_new(NULL, NULL, type);
	tnode_add(node, tree->root);
	tree->root = node;
	tree->curr = tree->curr->next;
	return (SUCCESS);
}
