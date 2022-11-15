/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:53:38 by jinam             #+#    #+#             */
/*   Updated: 2022/11/16 00:30:56 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipe.h"

static void	_close_fd(t_cmd_node *cmd)
{
	if (cmd->pipe[0] >= 0)
		close(cmd->pipe[0]);
	if (cmd->pipe[1] >= 0)
		close(cmd->pipe[1]);
}

void	exe_process(t_cmd_node *cmd, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_perror("pipex");
	if (pid == 0)
	{
		if (cmd->pipe[0] < 0 || cmd->pipe[1] < 0)
			exit(1);
		if (cmd->executables == 0)
		{
			ft_putstr_fd(cmd->cmd_args[0], 2);
			ft_putstr_fd(" command not found\n", 2);
			exit(1);
		}
		dup2(cmd->pipe[0], 0);
		close(cmd->pipe[0]);
		dup2(cmd->pipe[1], 1);
		close(cmd->pipe[1]);
		close(cmd->read_fd);
		execve(cmd->cmd_path, cmd->cmd_args, envp);
		ft_putstr_fd("pipex : execve failed\n", 2);
		exit(1);
	}
	_close_fd(cmd);
}

void	io_setting(int i, t_cmd_node *cmd, int fd1, int fd2)
{
	int			pip_res;
	static int	pipe_fd[2];

	pip_res = 0;
	if (i == 0)
	{
		cmd->pipe[0] = fd1;
		pip_res = pipe(pipe_fd);
		cmd->pipe[1] = pipe_fd[1];
	}
	else if (i == cmd->len - 1)
	{
		cmd->pipe[0] = pipe_fd[0];
		cmd->pipe[1] = fd2;
	}
	else
	{
		cmd->pipe[0] = pipe_fd[0];
		pip_res = pipe(pipe_fd);
		cmd->pipe[1] = pipe_fd[1];
	}
	if (pip_res == -1)
		ft_perror("pipex");
	cmd->read_fd = pipe_fd[0];
}

void	pipe_m_init_process(char *f1, char *f2, t_cmd_node **cmds, char *envp[])
{
	int			i;
	const int	fd1 = open(f1, O_RDONLY);
	const int	fd2 = open(f2, O_WRONLY | O_TRUNC | O_CREAT, 0644);

	if (fd1 == -1 || fd2 == -1)
		perror(f1);
	i = -1;
	while (cmds[++i] != NULL)
	{
		io_setting(i, cmds[i], fd1, fd2);
		exe_process(cmds[i], envp);
	}
	i = -1;
	while (cmds[++i] != NULL)
		wait(NULL);
}

int	main(int argc, char **argv, char *envp[])
{
	t_cmd_node	**cmd_paths;

	if (argc < 5)
	{
		ft_putstr_fd("pipex infile \"cmd1\" \"cmd2\" outfile", 2);
		exit(1);
	}
	cmd_paths = parsing_argv(argc - 3, argv + 2, envp);
	pipe_m_init_process(argv[1], argv[argc - 1], cmd_paths, envp);
}
