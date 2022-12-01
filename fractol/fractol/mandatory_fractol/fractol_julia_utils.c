/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:08:39 by jinam             #+#    #+#             */
/*   Updated: 2022/12/01 15:48:33 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_mlx *mlx)
{
	int	i;
	int	j;
	int	color;

	i = -1 * (VIEW / 2);
	while (i < VIEW / 2)
	{
		j = -1 * (VIEW / 2);
		while (j < (VIEW / 2))
		{
			color = j_get_color((int []){i, j}, &mlx->pnt, VIEW, mlx->m_cnt);
			my_mlx_pixel_put(&mlx->img, i + (VIEW / 2), j + (VIEW / 2), color);
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

unsigned int	j_get_color(int *xy, t_point *point, int line_len, int cnt)
{
	long double	x[3];
	long double	y[2];
	long double	temp_x;
	int			iter;

	iter = 0;
	x[0] = xy[0] * ((double) point->width / line_len) + point->x;
	y[0] = xy[1] * ((double) point->height / line_len) + point->y;
	while ((x[0] * x[0] + y[0] * y[0] <= 2 * 2) && (iter < 50))
	{
		x[2] = x[0] * x[0] - y[0] * y[0];
		y[0] = 2 * x[0] * y[0] + point->j_c_y;
		x[0] = x[2] + point->j_c_x;
		iter ++;
	}
	return (get_color(iter, cnt));
}
