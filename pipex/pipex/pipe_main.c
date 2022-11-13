/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:53:38 by jinam             #+#    #+#             */
/*   Updated: 2022/11/13 21:44:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipe.h"

void	exe_process(t_cmd_node *cmd, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_perror("pipex");
	if (pid == 0)
	{
		dup2(cmd->pipe[0], 0);
		close(cmd->pipe[0]);
		dup2(cmd->pipe[1], 1);
		close(cmd->pipe[1]);
		execve(cmd->cmd_path, cmd->cmd_args, envp);
		ft_printf("pipex : command not found\n");
		exit(1);
	}
	close(cmd->pipe[0]);
	close(cmd->pipe[1]);
}

void	_io_setting(int i, t_cmd_node *cmd, int fd1, int fd2)
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
}

void	pipe_m_init_process(char *f1, char *f2, t_cmd_node **cmds, char *envp[])
{
	int			i;
	const int	fd1 = open(f1, O_RDONLY);
	const int	fd2 = open(f2, O_WRONLY | O_TRUNC | O_CREAT, 0644);

	if (fd1 == -1 || fd2 == -1)
		ft_perror("pipex");
	i = -1;
	while (cmds[++i] != NULL)
	{
		_io_setting(i, cmds[i], fd1, fd2);
		exe_process(cmds[i], envp);
	}
	i = -1;
	while (cmds[++i + 1] != NULL)
		wait(NULL);
}

int	main(int argc, char **argv, char *envp[])
{
	t_cmd_node	**cmd_paths;

	if (ft_memcmp("here_doc", argv[0], ft_strlen("here_doc")) == 0)
		pipe_bonus(argc, argv, envp);
	if (argc < 5)
	{
		ft_putstr_fd("input error : pipex infile \"cmd1\" \"cmd2\" outfile", 2);
		exit(1);
	}
	cmd_paths = parsing_argv(argc - 3, argv + 2, envp);
	pipe_m_init_process(argv[1], argv[argc - 1], cmd_paths, envp);
}
