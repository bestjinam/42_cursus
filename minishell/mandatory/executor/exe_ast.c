/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:24:59 by dham              #+#    #+#             */
/*   Updated: 2023/01/25 15:47:12 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "ft_builtin.h"
#include "ft_signal.h"
#include "minishell.h"

void	exe_ast(t_astnode *node, int parent)
{
	if (!node)
		return ;
	ft_excute_signal_set();
	turn_on_show_signal();
	if (node->type == CMD || node->type == BRACKET_OPEN)
	{
		exe_pure_cmd(node, parent);
	}
	else if (node->type == PIPE)
	{
		exe_ast_pipe(node->left, node->right, 0);
	}
	else if (node->type == AND)
	{
		exe_ast_and(node->left, node->right, parent);
	}
	else if (node->type == OR)
	{
		exe_ast_or(node->left, node->right, parent);
	}
	ft_readline_signal_set();
}
