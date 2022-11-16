/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:54:27 by jinam             #+#    #+#             */
/*   Updated: 2022/11/16 16:38:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_BONUS_H
# define PIPE_BONUS_H
# include "../includes/ft_printf.h"
# include "../includes/libft.h"

typedef struct s_cmd_node
{
	int					len;
	int					idx;
	int					f1;
	int					read_fd;
	int					pipe[2];
	char				executables;
	char				*cmd_path;
	char				**cmd_args;
}	t_cmd_node;

t_cmd_node	**parsing_argv(int len, char **argv, char *envp[]);
void		io_setting(int i, t_cmd_node *cmd, int fd1, int fd2);
void		exe_process(t_cmd_node *cmd, char *envp[]);
void		pipe_bonus(int argc, char **argv, char *envp[]);
void		ft_perror(char *error);
void		ft_exit(char *str, int sig);
#endif
