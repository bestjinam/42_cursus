/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:30:16 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 20:18:18 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_built.h"
#include "../minishell_mandatory/minishell_mandatory.h"
#include <stdlib.h>

int	_str_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i ++;
	}
	return (1);
}

void	cmd_exit(char **argv, int status)
{
	if (status == 0)
		ft_putendl_fd("exit", 2);

	if (!argv[1])
		exit(g_info.return_code);
	else if (_str_is_num((char *) argv[1]) == 0)
	{
		ft_putstr_fd("minishell: exit:", 2);
		ft_putstr_fd((char *) argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_info.return_code = 255;
		exit(g_info.return_code);
	}
	else if (argv[2])
	{
		ft_putstr_fd("minishell: exit:", 2);
		ft_putstr_fd("too many arguments\n", 2);
		g_info.return_code = 1;
	}
	else
	{
		g_info.return_code = ft_atoi(argv[1]);
		exit(g_info.return_code);
	}
}
