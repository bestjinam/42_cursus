/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer_structure.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:12:22 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 16:04:54 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_LEXER_STRUCTURE_H
# define MS_LEXER_STRUCTURE_H

# include "libft.h"

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
	int			len;
}	t_cmd_list;

t_cmd_node	*cnode_new(char *data, int type);
void		cnode_add_back(t_cmd_list *lst, t_cmd_node *n);
t_cmd_node	*cnode_find(t_cmd_list *lst, char *data);
void		cnode_delete(t_cmd_list *lst, char *data);

#endif
