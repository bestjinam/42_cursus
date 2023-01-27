/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:19:15 by jinam             #+#    #+#             */
/*   Updated: 2023/01/18 15:43:32 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include "../includes/minishell_mandatory.h"
#include "minishell_built.h"
#include <stdlib.h>

void	_export_process(char *arg)
{
	char	**line;
	int		i;
	int		err_flag;

	err_flag = 0;
	line = ft_split(arg, '=');
	if (!line[0] || !check_name(line[0]))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		g_info.return_code = 1;
		err_flag = 1;
	}
	else if (enode_find(&g_info.env_list, line[0]))
	{
		err_flag = 1;
		if (line[1])
		{
			free(enode_find(&g_info.env_list, line[0])->val);
			enode_find(&g_info.env_list, line[0])->val = ft_strdup(line[1]);
		}
	}
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
	if (err_flag != 1)
		enode_add_back(&g_info.env_list, enode_new(arg));
}

void	_export_print(t_env_list *lst)
{
	int			i;
	t_env_node	*curr;

	curr = lst->head;
	i = 0;
	while (curr)
	{
		printf("declare -x ");
		if (!curr->val)
		{
			printf("%s", curr->name);
			curr = curr->next;
			i ++;
			continue ;
		}
		printf("%s=", curr->name);
		printf("\"%s\"\n", curr->val);
		curr = curr->next;
		i ++;
	}
}

void	cmd_export(char **argv)
{
	int			i;

	if (!argv[1])
	{
		_export_print(&g_info.env_list);
		g_info.return_code = 0;
		return ;
	}
	i = 1;
	while (argv[i])
	{
		_export_process((char *) argv[i]);
		i ++;
	}
}
