/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exe_builtin_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:53:16 by jinam             #+#    #+#             */
/*   Updated: 2023/01/15 19:28:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell_mandatory.h"
#include "../builtin/minishell_built.h"
#include <stdlib.h>

void	ms_exe_builtin(t_cmd_tnode *node, int idx)
{
	const char		**argv = _make_argv(node->string);
	const t_ms_fptr	bf[4] = {cmd_cd, cmd_echo, cmd_env, cmd_pwd};

	if (idx == 6)
		cmd_exit(argv, node->is_fork);
	else
		bf[idx](argv);
	free(argv);
}
