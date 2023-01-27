/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:21:39 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 20:18:08 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_mandatory/minishell_mandatory.h"
#include <stdlib.h>

void	cmd_env(char **argv)
{
	const char	**res = (const char **) enode_convert_char(&g_info.env_list);
	int			i;
	
	if (!*argv)
		return ;
	i = 0;
	while (res[i])
	{
		if (res[i])
		{
			printf("%s\n", res[i]);
			free((void *)res[i]);
		}
		i ++;
	}
	g_info.return_code = 0;
}

