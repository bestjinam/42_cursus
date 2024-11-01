/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:58:42 by jinam             #+#    #+#             */
/*   Updated: 2023/01/16 21:03:55 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int ac, char **av)
{
	int	ascii[128] = {0};
	int	i;
	int	j;

	if (ac < 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (av[1][i])
	{
		j = 0;
		while (av[2][j])
		{
			if (av[2][j] == av[1][i] && ascii[av[1][i]] == 0)
			{
				write(1, &av[1][i], 1);
				ascii[av[1][i]] = 1;
			}
			j ++;
		}
		i ++;
	}
	write(1, "\n", 1);
	return (0);
}
