/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:50:07 by jinam             #+#    #+#             */
/*   Updated: 2022/12/22 12:36:53 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"

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
	int			len;
} t_cmd_tree;

int	parsing_process(t_cmd_tree *tree, t_cmd_list *lexer_results);
t_list	*cmd_data_new(char *data, int type);
t_cmd_tnode	*tnode_new(t_list *str, t_list *re, int type);
t_cmd_tnode	*tnode_add(t_cmd_tnode **node, t_cmd_tnode *n);
void		tree_delete(t_cmd_tnode *tree);
t_cmd_tnode	*tnode_get_rlast(t_cmd_tnode *root);
#endif
