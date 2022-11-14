/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parsing_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:03:01 by jinam             #+#    #+#             */
/*   Updated: 2022/11/14 19:35:23 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

static char	*_make_whole_path(char *envpath, char *cmd)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(envpath, "/");
	res = ft_strjoin(tmp, cmd);
	free(tmp);
	return (res);
}

static char	**_parsing_envp(char *envp[])
{
	char	**res;
	int		i;

	i = -1;
	res = NULL;
	while (envp[++i])
	{
		if (ft_memcmp(envp[i], "PATH=", 5) == 0)
		{
			res = ft_split(&envp[i][5], ':');
		}
	}
	return (res);
}

static char	*_get_path(char *cmd, char *paths[])
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (paths[++i])
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		cmd_path = _make_whole_path(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

static int	is_empty_str(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ')
			return (0);
	}
	return (1);
}

t_cmd_node	**parsing_argv(int len, char **argv, char *envp[])
{
	t_cmd_node	**res;
	int			i;
	char		**envp_paths;

	envp_paths = _parsing_envp(envp);
	res = ft_malloc(sizeof(t_cmd_node *) * (len + 1));
	res[len] = NULL;
	i = -1;
	while (++i < len)
	{
		if (is_empty_str(argv[i]) == 1)
			ft_exit("pipex : syntax error", EXIT_FAILURE);
		res[i] = ft_malloc(sizeof(t_cmd_node));
		res[i]->cmd_args = ft_split(argv[i], ' ');
		res[i]->cmd_path = _get_path(res[i]->cmd_args[0], envp_paths);
		res[i]->executables = (res[i]->cmd_path != NULL);
		res[i]->len = len;
	}
	i = -1;
	while (envp_paths[++i])
		free(envp_paths[i]);
	free(envp_paths);
	return (res);
}
