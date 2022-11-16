/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:54:27 by jinam             #+#    #+#             */
/*   Updated: 2022/11/16 14:05:46 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include "../includes/ft_printf.h"
# include "../includes/libft.h"

typedef struct s_cmd_node
{
	int					idx;
	int					len;
	int					files[2];
	int					pipe[2];
	int					read_fd;
	char				executables;
	char				*cmd_path;
	char				**cmd_args;
}	t_cmd_node;

t_cmd_node	**parsing_argv(int len, char **argv, char *envp[]);
void		ft_perror(char *error);
void		ft_exit(char *str, int sig);
#endif
