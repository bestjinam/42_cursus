/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_make_options_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:11:02 by jinam             #+#    #+#             */
/*   Updated: 2022/11/16 00:22:09 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_bonus.h"

#include <stdlib.h>

int	ft_strslen(int size, char **strs)
{
	int	idx;
	int	sum;

	idx = 0;
	sum = 0;
	while (idx < size)
	{
		sum += ft_strlen(strs[idx]);
		idx ++;
	}
	return (sum);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 += ft_strlen(s1);
	while (*s2)
		*s1++ = *s2++;
	*s1 = 0;
	return (tmp);
}

char	*ft_strsjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*res;
	int		idx;

	len = ft_strslen(size, strs);
	res = malloc(sizeof(char) * (len + ft_strlen(sep) * (size - 1) + 1));
	if (!res)
		return (0);
	*res = 0;
	idx = 0;
	while (idx < size)
	{
		ft_strcat(res, strs[idx]);
		if (idx != size - 1)
			ft_strcat(res, sep);
		idx ++;
	}
	return (res);
}

void	get_trim_option(char **str)
{
	int		i;
	char	*tmp;
	char	**res;

	i = -1;
	res = malloc(sizeof(char *) * 3);
	res[2] = NULL;
	while (str[++i])
	{
		tmp = ft_strtrim(str[i], "\"\'");
		free(str[i]);
		str[i] = tmp;
	}
	res[0] = str[0];
	res[1] = ft_strsjoin(i - 1, &str[1], " ");
}
