/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:09:19 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 20:17:55 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell_mandatory.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char	*make_pwd(char *pwd, char *path)
{
	const int	len_s1 = ft_strlen(pwd);
	const int	len_s2 = ft_strlen(path);
	char		*res;

	res = ft_malloc(len_s1 + 1 + len_s2 + 1);
	ft_memmove(res, pwd, len_s1);
	ft_memmove(res + len_s1, "/", 1);
	ft_memmove(res + len_s1 + 1, path, len_s2);
	res[len_s1 + len_s2 + 1] = 0;
	return (res);
}

void	setting_cwd(char *path, char *key, int order)
{
	char				*cwd;
	const t_env_node	*env = enode_find(&g_info.env_list, key);

	cwd = getcwd(NULL, PATH_MAX);
	if (!cwd)
	{
		if (order == 0 && !env)
			return ;
		else if (order == 0 && env)
			cwd = ft_malloc(1);
		else if (order == 1)
		{
			if (env)
				cwd = make_pwd(env->val, path);
			ft_error_msg("cd: error retrieving current directory: ");
			perror("getcwd: cannot access parent directories:");
		}
	}
	if (env)
	{
		free(env->val);
		((t_env_node *)env)->val = cwd;
	}
}

void	exec_cd(char *path)
{
	int	res;

	setting_cwd(NULL, "OLDPWD", 0);
	res = chdir(path);
	if (res)
	{
		perror("cd:");
		g_info.return_code = 1;
		return ;
	}
	setting_cwd(path, "PWD", 1);
}

void	cmd_cd(char **argv)
{
	const t_env_node	*home_node = enode_find(&g_info.env_list, "HOME");

	if (!argv[1])
	{
		if (home_node && home_node->val)
			exec_cd(home_node->val);
		else
			ft_error_msg("YOU TRAPPED!!\n");
	}
	else
		exec_cd((char *)argv[1]);
}
