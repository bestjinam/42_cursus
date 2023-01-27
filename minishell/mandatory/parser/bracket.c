/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:34:41 by dham              #+#    #+#             */
/*   Updated: 2023/01/25 15:49:19 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "ft_builtin.h"
#include "ft_signal.h"
#include "minishell.h"

t_astnode	*bracket_tree(t_cmdlist *cmdlist)
{
	t_ast		tree_ast;
	t_astnode	*ret_node;

	tree_ast.root = NULL;
	cmdlist->current = cmdlist->current->next;
	if (!make_bracket_ast(cmdlist, &tree_ast))
	{
		clear_ast(tree_ast.root);
		return (NULL);
	}
	ret_node = init_astnode();
	ret_node->type = BRACKET_OPEN;
	ret_node->left = tree_ast.root;
	ret_node->right = init_astnode();
	ret_node->right->type = BRACKET_CLOSE;
	while (cmdlist->current && is_redirection(cmdlist->current->type))
	{
		if (!redir_proc(cmdlist, ret_node))
			return ((void *)(long)node_free_return (0, ret_node));
		cmdlist->current = cmdlist->current->next;
	}
	return (ret_node);
}
