/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft___lst_function_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:08:35 by jinam             #+#    #+#             */
/*   Updated: 2023/02/06 15:45:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <errno.h>

int	_lst_args_check(t_list *lst, void *f)
{
	errno = 0;
	if (lst == NULL)
		errno = EFAULT;
	if (f == NULL)
		errno = EINVAL;
	return (errno);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (_lst_args_check(lst, f))
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	t_list	*tail;

	if (_lst_args_check(lst, f))
		return (NULL);
	head = NULL;
	while (lst)
	{
		new_node = ft_lstnew(NULL);
		if (!new_node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		if (tail == NULL)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		lst = lst->next;
	}
	return (head);
}
