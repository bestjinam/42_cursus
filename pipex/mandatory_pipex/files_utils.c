/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:14:14 by jinam             #+#    #+#             */
/*   Updated: 2022/11/19 16:26:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

t_io_files	*open_files(char *f1, char *f2)
{
	t_io_files	*res;

	res = ft_malloc(sizeof(t_io_files));
	res->f1 = open(f1, O_RDONLY);
	if (res->f1 == -1)
		perror(f1);
	res->f2 = open(f2, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (res->f2 == -1)
		perror(f2);
	return (res);
}

void	close_fd(t_cmd *cmd)
{
	if (cmd->pipe[0] >= 0)
		close(cmd->pipe[0]);
	if (cmd->pipe[1] >= 0)
		close(cmd->pipe[1]);
}

void	io_setting(int i, t_cmd *cmd, int fd1, int fd2)
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
		ft_perror("pipex : pipe open");
	cmd->read_fd = pipe_fd[0];
}
