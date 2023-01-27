/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:16:27 by dham              #+#    #+#             */
/*   Updated: 2023/01/25 15:38:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	proc_cmd(char *cmd)
{
	t_cmdlist	cmdlist;
	t_ast		ast;
	t_strbuff	buff;
	char		*escape;

	escape = insert_escape(cmd, BACKSLASH_E);
	buff.str = escape;
	buff.len = ft_strlen(escape);
	buff.now_read = 0;
	init_list_ast(&cmdlist, &ast);
	if (!(make_cmdlist(&cmdlist, &buff) < 0 || !make_ast(&cmdlist, &ast)))
		exe_ast(ast.root, 1);
	turn_off_show_signal();
	clear_list(&cmdlist);
	clear_ast(ast.root);
	free(escape);
	return (0);
}
