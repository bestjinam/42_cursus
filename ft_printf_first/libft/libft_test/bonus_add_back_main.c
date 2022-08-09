/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_add_back_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:40:40 by jinam             #+#    #+#             */
/*   Updated: 2022/07/24 12:47:19 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*node;
	t_list	*back;

	back = ft_lstnew("abc");
	ft_lstadd_back(&node, back);
	printf("%s", (char *)node->content);
}
