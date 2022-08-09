/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:27:48 by jinam             #+#    #+#             */
/*   Updated: 2022/07/19 20:31:41 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	del(void *data)
{
	free(data);
	data = (void *) 0;
}

void	*f2(void *data)
{
	return (data);
}
void	f1(void *data)
{
	printf("%s\n", data);
}

int	main(void)
{
	printf("########################## BONUS #################################\n");
	printf(" >>> 1. lstnew <<<\n");
	printf("string HELLO -> lst node\n");
	t_list	*new;
	new = ft_lstnew(ft_strdup("HELLO"));
	printf("new-> content : %s\n", new->content);
	printf("\n");
	printf("null -> lst node\n");
	new = ft_lstnew(0);
	printf("new-> content : %s\n", new->content);
	printf("\n");
	printf(" >>> 2. lstadd_front <<<\n");
	t_list **lstadd_front_head;
	new = ft_lstnew(ft_strdup("HELLO"));
	t_list	*back;
	back = ft_lstnew(ft_strdup("WORLD"));
	ft_lstadd_front(&back, new);
	lstadd_front_head = &new;
	printf(" front_list = %s\n", (*lstadd_front_head)->content);
	printf(" front_list->next = %s\n", (*lstadd_front_head)->next->content);
	printf("\n");
	printf(" >>> 3. lstsize\n");
	printf("lstadd_front_head length = %d\n", ft_lstsize(*lstadd_front_head));
	printf("\n");
	printf(" >>> 4. lstlast\n");
	t_list *lstadd_front_head_last = ft_lstlast(*lstadd_front_head);
	printf("lstadd_front_head lastnode = %s\n", ft_lstlast(*lstadd_front_head)->content);
	printf(" >>> 5. lstadd_back\n");
	printf("lstadd_front_head + string(!!!) \n");
	printf("---- result(lstiter) ---- \n");
	ft_lstadd_back(lstadd_front_head, ft_lstnew(ft_strdup("!!!")));
	ft_lstiter(*lstadd_front_head, f1);
	printf("---- result(lstiter) ---- \n");
	printf(" >>> 6. ft_lstdelone\n");
	printf(" del last node\n");
	ft_lstdelone(ft_lstlast(*lstadd_front_head), del);
	printf(" del lastone \n");
	ft_lstiter(*lstadd_front_head, f1);

	printf(" >>> 7. ft_lstclear\n");
	lstadd_front_head_last->next = ft_lstnew(ft_strdup("!!!"));
	printf("---- result(lstiter) ---- \n");
	ft_lstiter(*lstadd_front_head, f1);
	printf("---- result(lstiter) ---- \n");

	printf(" >>> 8. ft_lstmap\n");
	t_list	*lstmap_input;
	t_list	*lstmap_result;

	char	*lstmap_strs;
	int		i;

	lstmap_strs = "01234";
	lstmap_input = ft_lstnew(&lstmap_strs[0]);
	i = 1;
	while (i < 5)
	{
		ft_lstadd_back(&lstmap_input, ft_lstnew(&lstmap_strs[i]));
		i ++;
	}
	lstmap_result = ft_lstmap(lstmap_input, f2, del);

	printf("---- result(lstiter) ---- \n");
	ft_lstiter(lstmap_input, f1);
	printf("---- result(lstiter) ---- \n");
	printf("########################## BONUS #################################\n");
}
