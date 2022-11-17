/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:45:41 by jinam             #+#    #+#             */
/*   Updated: 2022/11/17 17:05:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../includes/ft_printf.h"
# include "../includes/libft.h"

typedef struct s_io_files
{
	int	f1;
	int	f2;
}	t_io_files;

typedef struct s_cmd
{
	int					idx;
	int					pipe[2];
	int					read_fd;
	char				*cmd_paths;
	char				**cmd_args;
	char				execuatable;
	struct s_io_files	*files;
	int					len;
}	t_cmd;

// error
void		ft_perror(char *error);
void		ft_exit(char *str, int sig);
// files 
void		free_envp_paths(char **envp_paths);
int			is_empty_str(char *str);
char		**parsing_envp(char *envp[]);
char		*get_path(int idx, t_cmd *node, char *paths[]);
t_io_files	*open_files(char *f1, char *f2);
void		close_fd(t_cmd *cmd);
void		io_setting(int i, t_cmd *cmd, int fd1, int fd2);
void		get_random_tmp_file(char **str);
//
t_cmd		**parsing_argv(int len, char **argv, char *envp[]);
//
void		pipe_bonus_main(int argc, char **argv, char *envp[]);
void		pipe_m_init_process(t_cmd **cmds, char *envp[]);

#endif
