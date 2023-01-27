/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:30 by jinam             #+#    #+#             */
/*   Updated: 2023/01/18 15:52:59 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_mandatory.h"
#include "minishell_built.h"

void	_unset_process(char *argv)
{
	int			i;
	t_env_node	*node;

	i = 1;
	if (check_name(argv))
	{
		node = enode_find(&g_info.env_list, argv);
		if (node)
			enode_delete(&g_info.env_list, argv);
	}
	else
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		g_info.return_code = 1;
	}
}

void	cmd_unset(char **argv)
{
	int			i;

	if (!argv[1])
		return ;
	i = 1;
	while (argv[i])
	{
		_unset_process(argv[i]);
		i ++;
	}
}
