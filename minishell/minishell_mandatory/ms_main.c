/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:30:26 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 18:38:45 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell_mandatory.h"

t_info	g_info;

int	main(int argc, char **argv, char **envp)
{
	t_cmd_list	lexer_list;
	t_cmd_tree	parser_tree;
	int			tmp;
	char		*line;
	
	ms_init_all(&g_info.env_list, &lexer_list, &parser_tree);
	g_info.return_code = 0;
	while (1)
	{
		tmp = minishell_prompt(&line);
		if (tmp == EMPTY_PROMPT)
			continue ;
		minishell_lexer(line, &lexer_list);
		parser_tree.curr = lexer_list.head;
		tmp = minishell_parser(&parser_tree);
		if (tmp != SUCCESS_PROMPT)
		{
			while (lexer_list.len)
				cnode_delete(&lexer_list, lexer_list.head->data);
			tree_delete(parser_tree.root);
			parser_tree.root = NULL;
		}
		free(line);
	}
	exit (0);
}
