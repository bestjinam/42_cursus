/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:52:55 by jinam             #+#    #+#             */
/*   Updated: 2023/01/18 17:10:40 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_str_replace(char *ori, char *rep, int start, int len)
{
	const	int	r_len = ft_strlen(ori) + ft_strlen(rep) - len + 1;
	char	*res;

	res = malloc(r_len);
	ft_strlcpy(res, ori, start + 1);
	ft_strlcat(res, rep, r_len);
	ft_strlcat(res, &ori[start + len], r_len);
	return (res);
}
