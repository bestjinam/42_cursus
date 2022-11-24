/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:20 by jinam             #+#    #+#             */
/*   Updated: 2022/11/24 15:18:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MLX_TEST_H
# define MLX_TEST_H

# include "mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif
