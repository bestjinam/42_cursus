/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:48:40 by jinam             #+#    #+#             */
/*   Updated: 2022/11/21 12:16:20 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_process(t_cmd *cmd, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_perror("pipex fork");
	if (pid == 0)
	{
		if (cmd->pipe[0] < 0 || cmd->pipe[1] < 0)
			exit(1);
		if (cmd->execuatable == 0)
			exit(1);
		dup2(cmd->pipe[0], 0);
		close(cmd->pipe[0]);
		dup2(cmd->pipe[1], 1);
		close(cmd->pipe[1]);
		close(cmd->read_fd);
		execve(cmd->cmd_paths, cmd->cmd_args, envp);
		ft_perror(cmd->cmd_paths);
	}
	close_fd(cmd);
}

void	pipe_m_init_process(t_cmd **cmds, char *envp[])
{
	int	i;

	i = -1;
	while (cmds[++i] != NULL)
	{
		io_setting(i, cmds[i], cmds[i]->files->f1, cmds[i]->files->f2);
		exe_process(cmds[i], envp);
	}
	i = -1;
	while (cmds[++i] != NULL)
	{
		wait(NULL);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_cmd	**cmds;

	if (argc < 5)
	{
		ft_putstr_fd("pipex infile \"cmd1\" \"cmd2\" outfile", 2);
		exit(1);
	}
	cmds = parsing_argv(argc - 3, argv + 1, envp);
	pipe_m_init_process(cmds, envp);
	exit(0);
}
