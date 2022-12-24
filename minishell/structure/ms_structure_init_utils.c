/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structure_init_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:01:25 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 17:49:01 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ms_structure_init.h"

void	ms_env_init(t_env_list *env)
{
	env->head = (void *) 0;
	env->len = 0;
}

void	ms_lexer_init(t_cmd_list *lexer)
{
	lexer->head = NULL;
	lexer->tail = NULL;
	lexer->len = 0;
}

void	ms_parser_init(t_cmd_tree *parser)
{
	parser->curr = NULL;
	parser->root = NULL;
	parser->len = 0;
}

void	ms_init_all(t_env_list *e, t_cmd_list *l, t_cmd_tree *t)
{
	ms_env_init(e);
	ms_lexer_init(l);
	ms_parser_init(t);
}
