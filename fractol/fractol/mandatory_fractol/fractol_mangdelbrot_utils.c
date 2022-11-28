/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mangdelbrot_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:02:23 by jinam             #+#    #+#             */
/*   Updated: 2022/11/28 21:36:22 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



unsigned int	mb_get_color(int *xy, t_point *point, int line_len, int cnt)
{
	double	x[3];
	double	y[2];
	double			temp_x;
	int				iter;

	iter = 0;
	x[0] = xy[0] * ((double) point->width / line_len); 
	y[0] = xy[1] * ((double) point->height / line_len);
	x[1] = 0;
	y[1] = 0;
	while ((x[1] * x[1] + y[1] * y[1] <= 2 * 2) && (iter < 1000))
	{
		x[2] = x[1] * x[1] - y[1] * y[1] + x[0];
		y[1] = 2 * x[1] * y[1] + y[0];
		x[1] = x[2];
		iter ++;
	}
	return (get_color(iter, cnt));
}
