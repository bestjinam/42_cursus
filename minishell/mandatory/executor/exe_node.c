/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:32:45 by dham              #+#    #+#             */
/*   Updated: 2023/01/25 15:47:31 by jinam            ###   ########.fr       */
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

void	exe_ast_and(t_astnode *left_node, t_astnode *right_node, int parent)
{
	exe_ast(left_node, parent);
	if (g_info.ret_val == 0)
		exe_ast(right_node, parent);
}

void	exe_ast_or(t_astnode *left_node, t_astnode *right_node, int parent)
{
	exe_ast(left_node, parent);
	if (g_info.ret_val != 0)
		exe_ast(right_node, parent);
}

void	exe_ast_pipe(t_astnode *left_node, t_astnode *right_node, int input)
{
	int	pipe_fd[2];
	int	pid;
	int	last_pid;
	int	ret_val;

	pipe(pipe_fd);
	pid = exe_ast_cmd(left_node, input, pipe_fd[1], pipe_fd[0]);
	close(pipe_fd[1]);
	if (input != STDIN_FILENO)
		close(input);
	if (right_node->type == PIPE)
		exe_ast_pipe(right_node->left, right_node->right, pipe_fd[0]);
	else
	{
		last_pid = exe_ast_cmd(right_node, pipe_fd[0], 1, -1);
		close(pipe_fd[0]);
		waitpid(last_pid, &ret_val, 0);
		if (WIFEXITED(ret_val))
			g_info.ret_val = WEXITSTATUS(ret_val);
		else
			recieve_signal(ret_val);
	}
	waitpid(pid, &ret_val, 0);
}

int	exe_ast_cmd(t_astnode *node, int input, int output, int remain)
{
	int	pid;

	redirect_set(node);
	if (node->type == BRACKET_OPEN)
	{
		pid = exe_ast_bracket(node, input, output, remain);
		return (pid);
	}
	pid = fork();
	if (pid == 0)
	{
		ft_default_signal_set();
		if (remain >= 0)
			close(remain);
		input_set(input);
		output_set(output);
		exe_cmd_fork(node);
	}
	return (pid);
}

int	exe_ast_bracket(t_astnode *node, int input, int output, int remain)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_default_signal_set();
		if (remain >= 0)
			close(remain);
		input_set(input);
		output_set(output);
		if (!io_fd_set(node))
			exit(1);
		exe_ast(node->left, 0);
		exit(g_info.ret_val);
	}
	return (pid);
}
