/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:45:41 by jinam             #+#    #+#             */
/*   Updated: 2022/11/16 20:01:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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
t_io_files	*open_files(char *f1, char *f2);
void		close_fd(t_cmd *cmd);
void		io_setting(int i, t_cmd *cmd, int fd1, int fd2);

t_cmd		**parsing_argv(int len, char **argv, char *envp[]);
#endif
