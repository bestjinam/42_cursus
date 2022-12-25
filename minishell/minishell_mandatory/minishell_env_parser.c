/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:52:28 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 21:03:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell_mandatory.h"

void	minishell_env_parser(int argc, char **argv, char **envp)
{
	int	i;

	(void) argv;
	if (argc != 1)
		ft_exit("NO ARGS PLEASE!\n", 0);
	i = 0;
	while (envp[i])
	{
		enode_add_back(&g_info.env_list, enode_new(envp[i]));
		i ++;
	}
}
