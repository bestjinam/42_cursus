/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_structure.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:26:54 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 16:04:57 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSER_STRUCTURE_H
# define MS_PARSER_STRUCTURE_H

# include "libft.h"
# include "ms_lexer_structure.h"

typedef struct s_cmd_data
{
	char	*string;
	int		type;
}	t_cmd_data;

typedef struct s_cmd_tnode
{
	struct s_cmd_tnode	*r_node;
	struct s_cmd_tnode	*l_node;
	t_list				*string;
	t_list				*redirection;
	int					type;
}	t_cmd_tnode;

typedef struct s_cmd_tree
{
	t_cmd_tnode	*root;
	t_cmd_node	*curr;
	int			len;
} t_cmd_tree;

t_list		*cmd_data_new(char *data, int type);
t_cmd_tnode	*tnode_new(t_list *str, t_list *re, int type);
t_cmd_tnode	*tnode_add(t_cmd_tnode **node, t_cmd_tnode *n);
t_cmd_tnode	*tnode_get_rlast(t_cmd_tnode *root);
void		tree_delete(t_cmd_tnode *tree);
#endif
