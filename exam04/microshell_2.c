/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:23:28 by jinam             #+#    #+#             */
/*   Updated: 2023/04/04 11:34:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void	ft_putstr_fd(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	write(2, str, i);
}

int	ft_execute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_putstr_fd("error: cannot execute ");
	ft_putstr_fd(argv[0]);
	ft_putstr_fd("\n");
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	int	i;
	int	pid;
	int	fd[2];
	int	tmp_fd;

	pid = 0;
	i = 0;
	tmp_fd = dup(0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i ++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_putstr_fd("error: cd: bad arguments\n");
			else if (chdir(argv[1]) != 0)
			{
				ft_putstr_fd("error: cd: cannot change directory to ");
				ft_putstr_fd(argv[1]);
				ft_putstr_fd("\n");
			}
		}
		else if (argv != &argv[i] && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, 0);
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, 0, 0);
				tmp_fd = dup(0);
			}
		}
		else if (argv != &argv[i] && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, 0);
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				waitpid(-1, 0, 0);
				tmp_fd = dup(fd[0]);
				close(fd[0]);
			}
		}
	}
	close (tmp_fd);
	return (0);
}
