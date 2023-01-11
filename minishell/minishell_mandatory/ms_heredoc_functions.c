/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:01:38 by jinam             #+#    #+#             */
/*   Updated: 2023/01/11 20:32:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "minishell_mandatory.h"
#include <readline/readline.h>

static char	*_get_random_tmp_file(char *path)
{
	const int	fd = open("/dev/urandom", O_RDONLY);
	const char	*pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char		line[6];
	size_t		i;
	char		*res;

	read(fd, line, 5);
	i = 0;
	while (i < 5)
	{
		line[i] = pool[line[i] % (ft_strlen(pool))];
		i ++;
	}
	line[5] = 0;
	res = ft_strjoin((const char *) path, line);
	close(fd);
	return (res);
}

static void	_make_tmp_file(t_env_list *env, int *fd)
{
	t_env_node	*tmp_node;
	char		*path;
	char		*file;

	printf("here_doc return!\n");
	tmp_node = enode_find(env, "TMPDIR");
	if (!tmp_node)
		path = "./";
	else
		path = tmp_node->val;
	file = _get_random_tmp_file(path);
	fd[1] = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	fd[0] = open(file, O_RDONLY);
	unlink(file);
	free(file);
}

static void	_here_doc_process(int fd, char *end)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (line[0] == 0)
		{
			free(line);
			continue ;
		}
		if (ft_strncmp(line, end, ft_strlen(line) + 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
}

void	ms_heredoc(t_env_list *env, t_cmd_data *data)
{
	int			tmp_fd[2];

	_make_tmp_file(env, tmp_fd);
	_here_doc_process(tmp_fd[1], data->string);
	close(tmp_fd[1]);
	data->string = (char *)(long)tmp_fd[0];
}
