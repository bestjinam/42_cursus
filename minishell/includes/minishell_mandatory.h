/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_mandatory.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:11:38 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 18:29:29 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MANDATORY_H
# define MINISHELL_MANDATORY_H
# include "../includes/ms_env_structure.h"
# include "../includes/ms_lexer_structure.h"
# include "../includes/ms_parser_structure.h"
# include "../includes/ms_structure_init.h"

typedef struct s_info
{
	t_env_list	env_list;
	int			return_code;
} t_info;

enum e_prompt_returns
{
	EXIT_PROMPT,
	EMPTY_PROMPT,
	SUCCESS_PROMPT
};

extern t_info	g_info;

void	ft_error_msg(char *msg);
void	ft_exit(char *msg, int err_num);

int		minishell_prompt(char **str);
void	minishell_lexer(char *str, t_cmd_list *cmd_list);
int		minishell_parser(t_cmd_tree *tree);

#endif
