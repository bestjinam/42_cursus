/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing_argv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:52:23 by jinam             #+#    #+#             */
/*   Updated: 2022/11/16 20:10:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"

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
	while (envp && envp[++i])
	{
		if (ft_memcmp(envp[i], "PATH=", 5) == 0)
		{
			res = ft_split(&envp[i][5], ':');
		}
	}
	return (res);
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

static char	*_get_path(int idx, t_cmd *node, char *paths[])
{
	int			i;
	const char	*cmd = node->cmd_args[0];
	char		*cmd_path;

	i = -1;
	while (paths && paths[++i])
	{
		cmd_path = _make_whole_path(paths[i], (char *) cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	if (ft_strchr(cmd, '/') != NULL && access(cmd, F_OK | X_OK) == 0)
		return ((char *) cmd);
	if (idx == 0 && node->files->f1 < 0)
		return (NULL);
	perror("pipex cmd find");
	return (NULL);
}

t_cmd	**parsing_argv(int len, char **argv, char *envp[])
{
	t_cmd				**res;
	const t_io_files	*file = open_files(argv[0], argv[len + 1]);
	int					i;
	char				**envp_paths;

	envp_paths = _parsing_envp(envp);
	res = ft_malloc(sizeof(t_cmd *) * (len + 1));
	res[len] = NULL;
	i = -1;
	while (++i < len)
	{
		if (is_empty_str(argv[i + 1]) || !argv[i + 1])
			argv[i + 1] = "piepx_empty";
		res[i] = ft_malloc(sizeof(t_cmd));
		res[i]->files = (t_io_files *) file;
		res[i]->cmd_args = ft_split(argv[i + 1], ' ');
		res[i]->cmd_paths = _get_path(i, res[i], envp_paths);
		res[i]->execuatable = (res[i]->cmd_paths != NULL);
		res[i]->len = len;
	}
	i = -1;
	while (envp_paths && envp_paths[++i])
		free(envp_paths[i]);
	free(envp_paths);
	return (res);
}
