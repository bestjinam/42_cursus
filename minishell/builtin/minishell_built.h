/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_built.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:58:21 by jinam             #+#    #+#             */
/*   Updated: 2023/01/15 19:29:28 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILT_H
# define MINISHELL_BUILT_H

void	cmd_cd(const char **argv);
void	cmd_echo(const char **argv);
void	cmd_env(const char **argv);
void	cmd_pwd(const char **argv);
void	cmd_exit(const char **argv, int status);
typedef void	(*t_ms_fptr)(const char **);
#endif
