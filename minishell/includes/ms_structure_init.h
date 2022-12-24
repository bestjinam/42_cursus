/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structure_init.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:02:04 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 17:50:01 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCTURE_INIT_H
# define MS_STRUCTURE_INIT_H
# include "ms_env_structure.h"
# include "ms_lexer_structure.h"
# include "ms_parser_structure.h"

void	ms_env_init(t_env_list *env);
void	ms_lexer_init(t_cmd_list *lexer);
void	ms_parser_init(t_cmd_tree *parser);
void	ms_init_all(t_env_list *e, t_cmd_list *l, t_cmd_tree *t);
#endif
