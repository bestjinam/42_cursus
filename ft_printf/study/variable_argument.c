/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:27:17 by jinam             #+#    #+#             */
/*   Updated: 2022/08/01 14:29:19 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_numbers(int args, ...)
{
	printf("%d ", args);
}

int	main(void)
{
	print_numbers(1, 10);
	print_numbers(2, 10, 20);
	print_numbers(3, 10, 20, 30);
	print_numbers(4, 10, 20, 30, 40);
	return (0);
}
