/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:57:07 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 21:06:20 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ms_env_structure.h"
#include "../includes/libft.h"

t_env_node	*enode_new(char *str)
{
	t_env_node	*res;
	const char	*pos = ft_strchr(str, '=');
	int			name_len;

	name_len = pos - str;
	res = ft_malloc(sizeof(t_env_node));
	if (pos == NULL)
		name_len = ft_strlen(str);
	res->name = ft_substr(str, 0, name_len);
	if (pos != NULL)
		res->val = ft_substr(str, name_len + 1, ft_strlen(str) - name_len);
	res->next = NULL;
	return (res);
}

void	enode_add_back(t_env_list *lst, t_env_node *n)
{
	t_env_node	*curr;

	if (!lst->head)
		lst->head = n;
	else
	{
		curr = lst->head;
		while (curr->next)
			curr = curr->next;
		curr->next = n;
	}
	lst->len ++;
}

t_env_node	*enode_find(t_env_list *lst, char *name)
{
	t_env_node	*curr;
	int			cmp_result;

	curr = lst->head;
	while (curr)
	{
		cmp_result = ft_strncmp(curr->name, name, ft_strlen(name) + 1);
		if (curr->name && cmp_result == 0)
			break ;
		curr = curr->next;
	}
	return (curr);
}

void	enode_delete(t_env_list *lst, char *name)
{
	t_env_node	*curr;
	t_env_node	*prev;

	curr = lst->head;
	prev = NULL;
	while (curr)
	{
		if (ft_strncmp(curr->name, name, ft_strlen(name) + 1) == 0)
		{
			if (prev == NULL)
				lst->head = curr->next;
			else
				prev->next = curr->next;
			free(curr->name);
			free(curr->val);
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

char	**enode_convert_char(t_env_list *lst)
{
	char		**res;
	char		*tmp;
	int			i;
	t_env_node	*curr;

	res = ft_malloc(sizeof(char *) * (lst->len + 1));
	curr = lst->head;
	i = 0;
	while (curr)
	{
		if (!curr->val)
		{
			curr = curr->next;
			continue ;
		}
		tmp = ft_strjoin(curr->name, "=");
		res[i] = ft_strjoin(tmp, curr->val);
		free(tmp);
		curr = curr->next;
		i ++;
	}
	res[i] = 0;
	return (res);
}

