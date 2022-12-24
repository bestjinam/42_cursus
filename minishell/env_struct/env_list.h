/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:26:04 by jinam             #+#    #+#             */
/*   Updated: 2022/12/17 21:21:55 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

# include "../libft/libft/libft.h"
typedef struct s_env_node
{
	char				*name;
	char				*val;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_env_list
{
	struct s_env_node	*head;
	int					len;
}	t_env_list;

t_env_node	*enode_new(char *str);
void		enode_add_back(t_env_list *lst, t_env_node *n);
t_env_node	*enode_find(t_env_list *lst, char *name);
char		**enode_convert_char(t_env_list *lst);
void		enode_delete(t_env_list *lst, char *name);

#endif
