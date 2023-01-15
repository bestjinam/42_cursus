/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:30:26 by jinam             #+#    #+#             */
/*   Updated: 2023/01/15 18:20:35 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell_mandatory.h"

t_info	g_info;

void	_destroy_all(t_cmd_list *lexer_list, t_cmd_tree *parser, char *line)
{
	while ((lexer_list)->len)
		cnode_delete(lexer_list, (lexer_list)->head->data);
	tree_delete((parser)->root);
	(parser)->root = NULL;
	free(line);
}

void	_show_cmd_list(t_cmd_node *curr)
{
	while (curr)
	{
		printf(">> %s\n", curr->data);
		curr = curr->next;
	}
}

void	__printf_contents(void *curr)
{
	printf("%s -> ", ((t_cmd_data *) curr)->string);
}

void	_show_cmd_tree(t_cmd_tnode *root)
{
	t_list	*curr;

	if (!root)
		return ;
	curr = root->string;
	if (curr)
	{
		printf("%p\n", root);
		ft_lstiter(curr, __printf_contents);
	}
	else
		printf("type : %d", root->type);
	printf("\n");
	printf("#################################################\n");
	printf("%p %p \n", root->l_node, root->r_node);
	_show_cmd_tree(root->l_node);
	_show_cmd_tree(root->r_node);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd_list	lexer_list;
	t_cmd_tree	parser_tree;
	int			tmp;
	char		*line;

	ms_init_all(&g_info.env_list, &lexer_list, &parser_tree);
	minishell_env_parser(argc, argv, envp);
	g_info.return_code = 0;
	while (1)
	{
		tmp = minishell_prompt(&line);
		if (tmp == EMPTY_PROMPT)
			continue ;
		minishell_lexer(line, &lexer_list);
		parser_tree.curr = lexer_list.head;
		tmp = minishell_parser(&parser_tree);
		if (tmp != SUCCESS)
		{
			ft_error_msg("syntax error!\n");
			_destroy_all(&lexer_list, &parser_tree, line);
			continue ;
		}
		minishell_executer(parser_tree.root);
		_destroy_all(&lexer_list, &parser_tree, line);
	}
	system("leaks minishell");
	exit (0);
}
