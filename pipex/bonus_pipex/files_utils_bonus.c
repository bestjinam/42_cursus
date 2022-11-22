/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:14:14 by jinam             #+#    #+#             */
/*   Updated: 2022/11/21 12:14:05 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>

void	get_random_tmp_file(char **str)
{
	const int	fd = open("/dev/urandom", O_RDONLY);
	const char	*pool = "ABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvwxyz";
	char		line[6];
	size_t		i;

	read(fd, line, 5);
	i = 0;
	while (i < 5)
	{
		line[i] = pool[line[i] % (ft_strlen(pool))];
		i++;
	}
	line[5] = 0;
	*str = ft_strjoin((const char *) line, "_pipex.tmp");
	close(fd);
}

t_io_files	*open_files(char *f1, char *f2)
{
	t_io_files	*res;

	res = ft_malloc(sizeof(t_io_files));
	if (f1 == NULL)
	{
		res->f1 = 0;
		res->f2 = open(f2, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (res->f2 == -1)
			perror(f2);
	}
	else
	{
		res->f1 = open(f1, O_RDONLY);
		if (res->f1 == -1)
			perror(f1);
		res->f2 = open(f2, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (res->f2 == -1)
			perror(f2);
	}
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

void	free_envp_paths(char **envp_paths)
{
	int	i;

	i = -1;
	while (envp_paths && envp_paths[++i])
		free(envp_paths[i]);
	free(envp_paths);
}
