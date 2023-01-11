/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_executer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:57:41 by jinam             #+#    #+#             */
/*   Updated: 2023/01/11 20:28:32 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "minishell_mandatory.h"

void	ms_exe_and_or(t_cmd_tnode *lnode, t_cmd_tnode *rnode, int type)
{
	minishell_executer(lnode);
	if ((type == AND && g_info.return_code == SUCCESS) || \
			(type == OR && g_info.return_code != SUCCESS))
		minishell_executer(rnode);
}

int	ms_exe_fork_bracket(t_cmd_tnode *root, int wfd, int rfd, int remain)
{
	int	pid;
	int	re_res;

	pid = fork();
	if (pid == 0)
	{
		eu_fd_manage(wfd, rfd, remain);
		re_res = minishell_redirector(root->redirection);
		if (re_res == FILE_ERROR)
			return (FILE_ERROR);
		minishell_executer(root->l_node);
		exit(g_info.return_code);
	}
	return (pid);
}

int		ms_exe_fork_string(t_cmd_tnode *root, int wfd, int rfd, int remain)
{
	int		pid;
	int		re_res;

	pid = fork();
	if (pid == 0)
	{
		eu_fd_manage(wfd, rfd, remain);
		re_res = minishell_redirector(root->redirection);
		if (re_res == FILE_ERROR)
			return (FILE_ERROR);
		ms_execve_cmd(root);
		// execve()
		// exit
	}
	return (pid);
}


void	ms_exe_wait_bracket(t_cmd_tnode *root, int wfd, int rfd)
{
	int	pid;

	pid = ms_exe_fork_bracket(root, wfd, rfd, -1);
	if (pid == FILE_ERROR)
		exit(1);
	eu_setting_return_code(pid);
}

int	ms_exe_pipe_cmd(t_cmd_tnode *root, int wfd, int rfd, int remain)
{
	int pid;

	if (root->type == STRING)
		pid = ms_exe_fork_string(root, wfd, rfd, remain);
	else if (root->type == BR_OPEN)
		pid = ms_exe_fork_bracket(root, wfd, rfd, remain);
	else 
		pid = -1;
	return (pid);
}

void	ms_exe_pipe(t_cmd_tnode *root, int rfd)
{
	int	_pipe[2];
	int	l_pid;
	int	r_pid;

	pipe(_pipe);
	l_pid = ms_exe_pipe_cmd(root->l_node, _pipe[1], rfd, _pipe[0]);
	close (_pipe[1]);
	if (root->r_node->type == PIPE)
		ms_exe_pipe(root->r_node, _pipe[0]);
	else if (root->r_node->type == BR_OPEN)
		r_pid = ms_exe_fork_bracket(root->r_node, 1, _pipe[0], -1);
	else if (root->r_node->type == STRING)
		r_pid = ms_exe_fork_string(root->r_node, 1, _pipe[0], -1);
	if (root->r_node->type != PIPE)
		eu_setting_return_code(r_pid);
	waitpid(l_pid, 0, 0);
}

void	ms_exe_string(t_cmd_tnode *root)
{
	const int	fd1 = dup(0);
	const int	fd2 = dup(1);
	int			pid;

	printf("asdf#####\n");
	if (eu_is_builtin(root))
	{
		//ms_exe_builtin(root);
		dup2(fd1, 0);
		dup2(fd2, 1);
	}
	else
	{
		pid = ms_exe_fork_string(root, 1, 0, -1);
		eu_setting_return_code(pid);
	}
}

void	minishell_executer(t_cmd_tnode *root)
{
	if (root->type == AND)
	{
		ms_exe_and_or(root->l_node, root->r_node, root->type);
	}
	else if (root->type == OR)
	{
		ms_exe_and_or(root->l_node, root->r_node, root->type);
	}
	else if (root->type == BR_OPEN)
	{
		ms_exe_wait_bracket(root, 1, 0);
	}
	else if (root->type == PIPE)
	{
		ms_exe_pipe(root, 0);
	}
	else
	{
		ms_exe_string(root);
	}
}
