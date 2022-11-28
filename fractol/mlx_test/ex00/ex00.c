/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:23:53 by jinam             #+#    #+#             */
/*   Updated: 2022/11/25 14:30:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_test.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	t_mlx_instance	m; 
	t_data			info;

	if (argc < 3)
		return (1);
	m.mlx_instance = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx_instance, atoi(argv[1]), atoi(argv[2]), \
			"ex00 window");
	mlx_loop(m.mlx_instance);
	return (0);
}
