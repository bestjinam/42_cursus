/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_built.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:58:21 by jinam             #+#    #+#             */
/*   Updated: 2023/01/18 15:52:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILT_H
# define MINISHELL_BUILT_H

void	cmd_cd(char **argv);
void	cmd_echo(char **argv);
void	cmd_env(char **argv);
void	cmd_pwd(char **argv);
void	cmd_exit(char **argv, int status);
void	cmd_export(char **argv);
void	cmd_unset(char **argv);
int		check_name(const char *name);

typedef void	(*t_ms_fptr)(char **);
#endif
