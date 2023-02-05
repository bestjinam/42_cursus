/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:36:36 by jinam             #+#    #+#             */
/*   Updated: 2023/01/30 16:57:41 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define VIEW 10

int	main(void)
{
	int	i;
	int	j;
	int	color;

	i = VIEW / 2;
	while (i > -1 * VIEW / 2)
	{
		j = -1 * (VIEW / 2);
		while (j < VIEW / 2)
		{
			printf("x, y : %d, %d\n",j , i);
			j ++;
		}
		i --;
	}
}
