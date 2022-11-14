/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:38:56 by jinam             #+#    #+#             */
/*   Updated: 2022/11/14 21:13:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fcntl.h"
#include "pipe_bonus.h"
#include "../includes/get_next_line_bonus.h"

void	here_doc_process(char *end, int *hd_fd)
{
	char	*line;

	hd_fd[1] = open("/tmp/.pipex_tmp.tmp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	hd_fd[0] = open("/tmp/.pipex_tmp.tmp", O_RDONLY);
	unlink("/tmp/.pipex_tmp.tmp");
	while (1)
	{
		ft_printf("pipe here_doc > ");
		line = get_next_line(0);
		if (!line)
			break ;
		if (line[0] == '\n')
			continue ;
		if (ft_strncmp(line, end, ft_strlen(line) - 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, hd_fd[1]);
		free(line);
	}
}

void	pipe_b_init_process(int fd1, char *f2, t_cmd_node **cmds, char *envp[])
{
	int			i;
	const int	fd2 = open(f2, O_WRONLY | O_APPEND | O_CREAT, 0644);

	if (fd1 == -1 || fd2 == -1)
		perror("pipex");
	i = -1;
	while (cmds[++i] != NULL)
	{
		io_setting(i, cmds[i], fd1, fd2);
		exe_process(cmds[i], envp);
	}
	i = -1;
	while (cmds[++i + 1] != NULL)
		wait(NULL);
}

void	pipe_bonus(int argc, char **argv, char *envp[])
{
	int			hd_fd[2];
	t_cmd_node	**cmd_paths;

	if (argc < 6)
	{
		ft_putstr_fd("input error : pipex here_doc LIMITER \"cmd\" \"cmd\" file", 2);
		exit(1);
	}
	here_doc_process(argv[2], hd_fd);
	cmd_paths = parsing_argv(argc - 4, argv + 3, envp);
	close(hd_fd[1]);
	pipe_b_init_process(hd_fd[0], argv[argc - 1], cmd_paths, envp);
	system("leaks pipex");
}
