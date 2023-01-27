/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_mandatory.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:11:38 by jinam             #+#    #+#             */
/*   Updated: 2023/01/19 16:51:17 by jinam            ###   ########.fr       */
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
}	t_info;

enum e_returntype
{
	EXIT_PROMPT,
	EMPTY_PROMPT,
	SUCCESS,
	SYNTAX_ERROR,
	FILE_ERROR,
};

extern t_info	g_info;

int			destroy_error_trees(t_cmd_tree *root, t_cmd_tnode *node);
void		ft_error_msg(char *msg);
void		ft_exit(char *msg, int err_num);

void		eu_setting_return_code(int pid);
int			eu_is_builtin(t_cmd_tnode *root);
void		eu_fd_manage(int rfd, int wfd, int remain);

void		minishell_env_parser(int argc, char **argv, char **envp);
int			minishell_prompt(char **str);
int			minishell_lexer(char *str, t_cmd_list *cmd_list);
int			minishell_parser(t_cmd_tree *tree);
void		minishell_executer(t_cmd_tnode *root);
int			minishell_redirector(t_list *head);

int			pu_is_redirect(int type);
int			pu_is_operator(t_cmd_node *node);
t_cmd_tnode	*pu_make_cmd_tnode(t_cmd_tree *t);
int			pu_br_redirect(t_cmd_tree *tree);

int			ms_parser_string(t_cmd_tree *tree);
int			ms_parser_and_or(t_cmd_tree *tree);
void		ms_heredoc(t_env_list *env, t_cmd_data *data);

void		ms_execve_cmd(t_cmd_tnode *node);
void		ms_exe_builtin(t_cmd_tnode *node, int idx);

char		**_make_argv(t_list *cmdlist);

#endif
