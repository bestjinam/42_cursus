/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_bracket_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:20:18 by jinam             #+#    #+#             */
/*   Updated: 2022/12/29 13:30:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell_mandatory.h"
#include <stdlib.h>

int	destroy_error_trees(t_cmd_tree *root, t_cmd_tnode *node)
{
	free(root->root);
	free(node);
	free(root);
	return (SYNTAX_ERROR);
}
