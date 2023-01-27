/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execve_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:29:23 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 20:25:41 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell_mandatory.h"

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


static char	*_make_whole_path(char *envpath, char *cmd)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(envpath, "/");
	res = ft_strjoin(tmp, cmd);
	free(tmp);
	return (res);
}

static const char	*_get_path(const char *cmd, const char *paths[])
{
	int			i;
	char		*cmd_path;

	i = -1;
	while (paths && paths[++i])
	{
		cmd_path = _make_whole_path((char *) paths[i], (char *) cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

char **_make_argv(t_list *cmdlist)
{
	const int	len = ft_lstsize(cmdlist);
	int			i;
	char		**res;

	res = ft_malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (cmdlist)
	{
		res[i] = ((t_cmd_data *)cmdlist->content)->string;
		i ++;
		cmdlist = cmdlist->next;
	}
	res[len] = 0;
	return (res);
}

void	ms_execve_cmd(t_cmd_tnode *node)
{
	const char	**argvs = (const char **)_make_argv(node->string);
	const char	**envps = (const char **) enode_convert_char(&g_info.env_list);
	const char	**path_envp = (const char **) _parsing_envp((char **) envps);
	const char	*path = _get_path(argvs[0], path_envp); 

	execve(path, (char **)argvs, (char **)envps);
	ft_putstr_fd("cmd not found\n", 2);
	g_info.return_code = 127;
	exit(127);
}
