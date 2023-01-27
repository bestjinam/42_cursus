/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:31:53 by jinam             #+#    #+#             */
/*   Updated: 2023/01/19 16:47:11 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_mandatory.h"

int	_check_dollar(char *str)
{
	int	i;
	int	quotes;
	int	dq;
	int	len;

	i = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == '\"' && quotes == 0)
		if (str[i] == '\"' && quotes == 2)
		if (str[i] == '\'' && quotes == 0)
		if (str[i] == '\'' && quotes == 1)
		i ++;
	}
}

char	**minishell_expander(char **argv)
{
	int		i;
	char	**tmp;
	int		elen;

	i = 0;
	while (argv[i])
	{
		elen = _check_dollar(argv[i]);
	}
}
