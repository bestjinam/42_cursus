/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:58:30 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 20:18:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_mandatory/minishell_mandatory.h"
#include "minishell_built.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	cmd_pwd(char **argv)
{
	const t_env_node	*env = enode_find(&g_info.env_list, "PWD");
	const char			*cwd = getcwd(NULL, PATH_MAX);

	if (!argv)
		return ;
	if (!cwd)
	{
		if (!env || !env->val)
		{
			ft_putstr_fd("pwd: error\n", 2);
			g_info.return_code = 1;
			return ;
		}
		else
			printf("%s\n",env->val);
	}
	else
		printf("%s\n", cwd);
	free((void *)cwd);
	g_info.return_code = 0;
}
