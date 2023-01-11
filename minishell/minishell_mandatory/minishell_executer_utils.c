/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_executer_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:59:10 by jinam             #+#    #+#             */
/*   Updated: 2023/01/11 20:04:27 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell_mandatory.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	eu_setting_return_code(int pid)
{
	int	res;

	waitpid(pid, &res, 0);
	if (WIFEXITED(res))
		g_info.return_code = WEXITSTATUS(res);
	else
	{
		if (WTERMSIG(res) == SIGINT)
			g_info.return_code = 130;
		else
			g_info.return_code = 131;
	}
}

void	eu_fd_manage(int wfd, int rfd, int remain)
{
	dup2(rfd, 0);
	dup2(wfd, 1);
	if (rfd != STDIN_FILENO)
		close(rfd);
	if (wfd != STDOUT_FILENO)
		close(wfd);
	if (remain >= 0)
		close(remain);
}

int	eu_is_builtin(t_cmd_tnode *root)
{
	const char		*list[7] = {"echo", "cd", "pwd", "export", \
								"unset", "env", "exit"};
	const char		*data = root->string->content;
	int			i;

	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(list[i], data, ft_strlen(list[i]) + 1) == 0)
			return (1);
		i ++;
	}
	return (0);
}
