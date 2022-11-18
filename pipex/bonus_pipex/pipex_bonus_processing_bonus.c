/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_processing_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:24:38 by jinam             #+#    #+#             */
/*   Updated: 2022/11/18 14:31:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"
#include <fcntl.h>
#include "../includes/get_next_line_bonus.h"

void	make_tempfile(char **file, int *hd_fd)
{
	get_random_tmp_file(file);
	hd_fd[1] = open(*file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	hd_fd[0] = open(*file, O_RDONLY);
	unlink(*file);
}

void	here_doc_process(char *end, int *hd_fd)
{
	char	*line;
	char	*file;

	make_tempfile(&file, hd_fd);
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(0);
		if (!line)
			break ;
		if (line[0] == '\n' && end[0] != 0)
		{
			free(line);
			continue ;
		}
		if (ft_strncmp(line, end, ft_strlen(line) - 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, hd_fd[1]);
		free(line);
	}
	free(file);
}

t_cmd	**parsing_argv_here_doc(int len, char **argv, char *envp[], int *fd)
{
	t_cmd				**res;
	int					i;
	char				**envp_paths;
	t_io_files			*file;

	envp_paths = parsing_envp(envp);
	file = open_files(NULL, argv[len + 1]);
	file->f1 = fd[0];
	res = ft_malloc(sizeof(t_cmd *) * (len + 1));
	res[len] = NULL;
	i = -1;
	while (++i < len)
	{
		if (is_empty_str(argv[i + 1]) || !argv[i + 1])
			argv[i + 1] = "(NULL)";
		res[i] = ft_malloc(sizeof(t_cmd));
		res[i]->files = (t_io_files *) file;
		res[i]->cmd_args = ft_split(argv[i + 1], ' ');
		res[i]->cmd_paths = get_path(i, res[i], envp_paths);
		res[i]->execuatable = (res[i]->cmd_paths != NULL);
		res[i]->len = len;
	}
	free_envp_paths(envp_paths);
	return (res);
}

void	pipe_bonus_main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_cmd	**cmds;

	if (argc < 6)
	{
		ft_putstr_fd("./pipex here_doc LIMITER cmd cmd file", 2);
		exit(1);
	}
	here_doc_process(argv[2], fd);
	cmds = parsing_argv_here_doc(argc - 4, argv + 2, envp, fd);
	pipe_m_init_process(cmds, envp);
	exit(0);
}
