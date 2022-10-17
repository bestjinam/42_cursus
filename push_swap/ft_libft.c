/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:18:18 by jinam             #+#    #+#             */
/*   Updated: 2022/10/17 20:39:32 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "push_swap.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*t_s2;
	unsigned char	*t_s1;

	if (!(s1) && !(s2))
		return (0);
	t_s1 = (unsigned char *) s1;
	t_s2 = (unsigned char *) s2;
	i = -1;
	while (++i < n)
		t_s1[i] = t_s2[i];
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	while (*tmp_s)
	{
		if (*tmp_s == (unsigned char) c)
			return ((char *) tmp_s);
		tmp_s++;
	}
	if (c == 0)
		return ((char *) tmp_s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*res;

	s_len = ft_strlen(s);
	if (s_len <= start)
		sub_len = 1;
	else if (ft_strlen(s + start) <= len)
		sub_len = ft_strlen(s + start) + 1;
	else
		sub_len = len + 1;
	res = malloc(sizeof(char) * (sub_len));
	if (!res)
		return (0);
	ft_memcpy(res, s + start, sub_len);
	return (res);
}

