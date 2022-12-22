/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:50:39 by jinam             #+#    #+#             */
/*   Updated: 2022/12/22 21:04:23 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../libft/libft/libft.h"
enum e_token_type
{
	STRING,
	RE_IN,
	RE_OUT,
	RE_APPEND,
	RE_HEREDOC,
	PIPE,
	BR_OPEN,
	BR_CLOSE,
	AND,
	OR
};

typedef struct s_cmd_node
{
	char				*data;
	int					type;
	struct s_cmd_node	*prev;
	struct s_cmd_node	*next;
}	t_cmd_node;

typedef struct s_cmd_list
{
	t_cmd_node	*head;
	t_cmd_node	*tail;
	t_cmd_node	*curr;
	int			len;
}	t_cmd_list;

t_cmd_node	*cmd_node_new(char *data, int type);
void		cmd_node_add_back(t_cmd_list *lst, t_cmd_node *n);
t_cmd_node	*cmd_node_find(t_cmd_list *lst, char *data);
void		cmd_node_delete(t_cmd_list *lst, char *data);

void	minishell_lexer(char *str, t_cmd_list *cmd_list);

#endif
