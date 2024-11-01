/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:29:39 by dham              #+#    #+#             */
/*   Updated: 2023/01/25 15:51:44 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_builtin.h"
#include "ft_signal.h"
#include "minishell.h"

char	*search_cmd(char *cmd, char *envp[])
{
	char	**path;
	char	*ret_path;
	int		i;

	i = 0;
	path = path_list(envp);
	if ((!*cmd || !path) && !command_err(cmd))
		return (ft_strdup(cmd));
	ret_path = path_join(path[i], cmd);
	while (access(ret_path, F_OK) == -1 && path[i])
	{
		free(ret_path);
		i++;
		if (!path[i])
			break ;
		ret_path = path_join(path[i], cmd);
	}
	if (!path[i])
		command_err(cmd);
	else if (access(ret_path, X_OK) == -1 && !common_error(ret_path))
		g_info.ret_val = 126;
	free_path_list(path);
	return (ret_path);
}

char	*path_join(char *path, char *cmd)
{
	char	*ret_str;
	int		path_len;
	int		cmd_len;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	ret_str = malloc(path_len + cmd_len + 2);
	ft_strlcpy(ret_str, path, path_len + 1);
	ft_strlcat(ret_str, "/", path_len + 2);
	ft_strlcat(ret_str, cmd, path_len + cmd_len + 2);
	return (ret_str);
}

char	**path_list(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (envp[i] && ft_strncmp(envp[i], "PATH=", 5) == 0)
		return (ft_split(&envp[i][5], ':'));
	else
		return (NULL);
}

void	free_path_list(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
