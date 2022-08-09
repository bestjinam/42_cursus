/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_temp_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:22:09 by jinam             #+#    #+#             */
/*   Updated: 2022/08/09 12:33:50 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_temp_print(t_temp_str *temp_str, int fd)
{
	size_t	res;
	size_t	tmp;

	res = 0;
	while (1)
	{
		tmp = write(fd, &temp_str->str[res], (temp_str->len - res));
		if (tmp < 0)
			return (-1);
		res += tmp;
		if (res == temp_str->len)
			return (res);
	}
}
