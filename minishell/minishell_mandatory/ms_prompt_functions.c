/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:36:29 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 21:17:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell_mandatory.h"

static void	get_readline(char **str, char *prompt)
{
	*str = readline(prompt);
	if (*str && **str)
		add_history(*str);
}

static int	_isspace(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i ++;
	}
	return (1);
}

int	minishell_prompt(char **res)
{
	get_readline(res, "minishell$ ");
	if (!*res)
	{
		printf("\033[1A\033[%dCexit", (int)ft_strlen("minishell$ "));
		free(*res);
		ft_exit("", 1);
	}
	if (_isspace(*res) == 1)
	{
		free(*res);
		return (EMPTY_PROMPT);
	}
	return (SUCCESS);
}
