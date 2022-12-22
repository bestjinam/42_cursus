/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:29:22 by jinam             #+#    #+#             */
/*   Updated: 2022/12/22 21:48:24 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../libft/libft/libft.h"
#include "lexer.h"
#include "parser.h"

int	_is_redirections(int type)
{
	return (type == RE_IN || type == RE_OUT || type == RE_APPEND \
			|| type == RE_HEREDOC);
}

t_cmd_node	*_cmd_tnode_new(t_cmd_tnode **tree, t_cmd_node *lexer_cmd)
{
	t_list	*tmp;

	*tree = ft_malloc(sizeof(t_cmd_tnode));
	while (lexer_cmd && lexer_cmd->type < PIPE)
	{
		if (lexer_cmd->type == STRING)
			ft_lstadd_back(&(*tree)->string, cmd_data_new(lexer_cmd->data,\
						lexer_cmd->type)); 
		else
		{
			if (!lexer_cmd->next || lexer_cmd->next->type != STRING)
				break ; //error 문구처리 
			tmp = cmd_data_new(lexer_cmd->next->data, lexer_cmd->type);
			if (_is_redirections(lexer_cmd->type))
			{
				ft_lstadd_back(&(*tree)->redirection, tmp);
				lexer_cmd = lexer_cmd->next;
			}
			else 
				break ; //error 
		}
		if (!lexer_cmd->next || lexer_cmd->next->type >= PIPE)
			return (lexer_cmd);
		lexer_cmd = lexer_cmd->next;
	}
	return (lexer_cmd->prev);
}

void	_pipe_tnode_new(t_cmd_tnode **tree, t_cmd_node *lexer_cmd)
{
	t_cmd_tnode	*right_node;
	t_cmd_tnode	*tmp;

	right_node = tnode_get_rlast(*tree);
	if ((*tree)->type == STRING)
	{
		tmp = tnode_new(NULL, NULL, lexer_cmd->type);
		tnode_add(&tmp, *tree);
		*tree = tmp;
		return ;
	}
	tmp = right_node->r_node;
	right_node->r_node = tnode_new(NULL, NULL, lexer_cmd->type);
	right_node->r_node->l_node = tmp;
}

t_cmd_node	*_bracket_tnode_new(t_cmd_tree *tree, t_cmd_node *curr)
{
	t_cmd_tnode	*tmp;

	while (curr && curr->type != BR_CLOSE)
	{
		if (curr->type == STRING)
		{
			curr = _cmd_tnode_new(&tmp, curr);
			tnode_add(&tree->root, tmp);
		}
		else if (curr->type == AND || curr->type == OR)
		{
			tmp = tnode_new(NULL, NULL, curr->type);
			tnode_add(&tmp, tree->root);
			tree->root = tmp;
		}
		else if (curr->type == PIPE)
			_pipe_tnode_new(&tree->root, curr);
		if (!curr || !curr->next)
			return (curr);
		curr = curr->next;
	}
	return (curr);
}

t_cmd_node	*_parsing_br_redirection(t_cmd_tnode **broot, t_cmd_node *curr)
{	
	t_list	*tmp;

	while (_is_redirections(curr->type))
	{
		tmp = cmd_data_new(curr->next->data, curr->type);
		ft_lstadd_back(&(*broot)->redirection, tmp);
		if (!curr->next)
			break;
		if (!curr->next->next)
			return (curr->next);
		curr = curr->next->next;
	}
	return (curr);
}

int	parsing_process(t_cmd_tree *tree, t_cmd_list *lexer_results)
{
	t_cmd_node	*curr;
	t_cmd_tree	*tmp_tree;
	t_cmd_tnode	*tmp;

	curr = lexer_results->head;
	tmp = NULL;
	while (curr)
	{
		if (curr->type == STRING)
		{
			printf("adsfasdfadsfadfasdfdasf\n");
			curr = _cmd_tnode_new(&tmp, curr);
			tnode_add(&tree->root, tmp);
		}
		else if (curr->type == AND || curr->type == OR)
		{
			printf("asdfasdf*(*(*(*(*(*(*(*(*))))))))\n");
			tmp = tnode_new(NULL, NULL, curr->type);
			tnode_add(&tmp, tree->root);
			tree->root = tmp;
		}
		else if (curr->type == PIPE)
			_pipe_tnode_new(&tree->root, curr);
		else if (curr->type == BR_OPEN)
		{
			tmp_tree = ft_malloc(sizeof(t_cmd_tree));	
			tmp = tnode_new(NULL, NULL, curr->type);
			curr = _bracket_tnode_new(tmp_tree, curr->next);
			/*if (curr == NULL) == > error */
			tnode_add(&tmp, tmp_tree->root);
			tmp->r_node = tnode_new(NULL, NULL, curr->type);
			if (!tree->root)
				tree->root = tmp;
			else
				tnode_get_rlast(tree->root)->r_node = tmp;		
			if (curr && curr->next&& _is_redirections(curr->next->type))
				curr = _parsing_br_redirection(&tmp_tree->root, curr->next);
			free(tmp_tree);
		}
		if (!curr)
			break ;
		curr = curr->next;
	}
	return (0);
}
