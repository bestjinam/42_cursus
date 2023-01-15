/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:26:06 by jinam             #+#    #+#             */
/*   Updated: 2023/01/13 20:22:23 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell_mandatory.h"

int	ms_parser_string(t_cmd_tree *tree)
{
	t_cmd_tnode	*res;

	res = pu_make_cmd_tnode(tree);
	if (!res)
		return (SYNTAX_ERROR);
	if (!tree->root)
		tree->root = res;
	else
		tnode_add(tnode_get_rlast(tree->root), res);
	return (SUCCESS);
}

int	ms_parser_pipe(t_cmd_tree *tree)
{
	t_cmd_tnode	*right_node;
	t_cmd_tnode	*tmp;

	if (!tree->curr->next)
		return (SYNTAX_ERROR);
	if (tree->root->type == STRING)
	{
		tmp = tnode_new(NULL, NULL, tree->curr->type);
		tnode_add(tmp, tree->root);
		tree->root = tmp;
	}
	else
	{
		right_node = tnode_get_rlast(tree->root);
		tmp = right_node->r_node;
		right_node->r_node = tnode_new(NULL, NULL, tree->curr->type);
		right_node->r_node->l_node = tmp;
	}
	tree->curr = tree->curr->next;
	return (SUCCESS);
}

static int	_make_br_tree(t_cmd_tree *tree)
{
	int	res;

	while (tree->curr && tree->curr->type != BR_CLOSE)
	{
		if (tree->curr->type == STRING)
			res = ms_parser_string(tree);
		else if (tree->curr->type == PIPE)
			res = ms_parser_pipe(tree);
		else if (tree->curr->type == AND || tree->curr->type == OR)
			res = ms_parser_and_or(tree);
		else
			res = SYNTAX_ERROR;
		if (res != SUCCESS)
			break ;
	}
	if (!tree->curr || tree->curr->type != BR_CLOSE)
		return (SYNTAX_ERROR);
	return (SUCCESS);
}

int	ms_parser_bracket(t_cmd_tree *tree)
{
	int			res;
	t_cmd_tnode	*open;
	t_cmd_tree	*b_tree;

	b_tree = ft_malloc(sizeof(t_cmd_tree));
	open = tnode_new(NULL, NULL, tree->curr->type);
	b_tree->curr = tree->curr->next;
	if (_make_br_tree(b_tree) == SYNTAX_ERROR)
		return (destroy_error_trees(b_tree, open));
	tnode_add(open, b_tree->root);
	open->r_node = tnode_new(NULL, NULL, BR_CLOSE);
	tree->curr = b_tree->curr->next;
	if (!tree->root)
		tree->root = open;
	else
		tnode_get_rlast(tree->root)->r_node = open;
	res = SUCCESS;
	if (tree->curr && pu_is_redirect(tree->curr->type))
		res = pu_br_redirect(tree);
	free(b_tree);
	return (res);
}

int	minishell_parser(t_cmd_tree *tree)
{
	int			res;

	if (pu_is_operator(tree->curr))
		return (SYNTAX_ERROR);
	while (tree->curr)
	{
		if (tree->curr->type == STRING || pu_is_redirect(tree->curr->type))
			res = ms_parser_string(tree);
		else if (tree->curr->type == PIPE)
			res = ms_parser_pipe(tree);
		else if (tree->curr->type == BR_OPEN)
		{
			if (!tree->curr->next || pu_is_operator(tree->curr->next))
				res = SYNTAX_ERROR;
			else
				res = ms_parser_bracket(tree);
		}
		else if (tree->curr->type == AND || tree->curr->type == OR)
			res = ms_parser_and_or(tree);
		else
			res = SYNTAX_ERROR;
		if (res != SUCCESS)
			break ;
	}
	return (res);
}
