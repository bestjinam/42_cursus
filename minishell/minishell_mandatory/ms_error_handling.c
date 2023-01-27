/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:10:11 by jinam             #+#    #+#             */
/*   Updated: 2023/01/19 16:48:26 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include "minishell_mandatory.h"

void	ft_error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
}

void	ft_exit(char *msg, int err_num)
{
	ft_error_msg(msg);
	exit(err_num);
}

int	destroy_error_trees(t_cmd_tree *root, t_cmd_tnode *node)
{
	free(root->root);
	free(node);
	free(root);
	return (SYNTAX_ERROR);
}
