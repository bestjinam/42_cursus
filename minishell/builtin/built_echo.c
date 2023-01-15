/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:53:52 by jinam             #+#    #+#             */
/*   Updated: 2023/01/15 17:40:56 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include "minishell_built.h"
#include "../minishell_mandatory/minishell_mandatory.h"
#include <stdio.h>

int	is_option(const char *cmd)
{
	const char	opt = 'n';
	size_t		i;

	i = 1;
	while (cmd[i] && cmd[0] == '-' && cmd[i] == opt)
		i ++;
	if (ft_strlen(cmd) != i)
		return (0);
	return (1);
}

void	cmd_echo(const char **argv)
{
	size_t		i;
	const int	option = is_option(argv[1]);

	i = 1;
	if (option == 1)
		i = 2;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i ++;
	}
	if (option == 0)
		printf("\n");
	g_info.return_code = 0;
}
