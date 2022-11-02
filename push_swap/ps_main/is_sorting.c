/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:28:00 by jinam             #+#    #+#             */
/*   Updated: 2022/11/02 10:17:26 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_main.h"

int	is_sorting(int *arr, int *input, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (arr[i] != input[i])
			return (0);
	}
	return (1);
}
