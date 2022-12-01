/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_custom_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:02:23 by jinam             #+#    #+#             */
/*   Updated: 2022/12/01 16:02:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	abs_num(long double num)
{
	return ( num * ((num > 0) - (num < 0)));
}

unsigned int	c_get_color(int *xy, t_point *point, int line_len, int cnt)
{
	long double	x[3];
	long double	y[2];
	long double	temp_x;
	int			iter;

	iter = 0;
	x[0] = xy[0] * ((double) point->width / line_len) + point->x;
	y[0] = xy[1] * ((double) point->height / line_len) + point->y;
	x[1] = 0;
	y[1] = 0;
	while ((x[1] * x[1] + y[1] * y[1] <= 2 * 2) && (iter < 50))
	{
		x[2] = x[1] * x[1] - y[1] * y[1] + abs_num(x[0]);
		y[1] = 2 * x[1] * y[1] + y[0];
		x[1] = x[2];
		iter ++;
	}
	return (get_color(iter, cnt));
}

void	draw_custom(t_mlx *mlx)
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
			color = c_get_color((int []){i, j}, &mlx->pnt, VIEW, mlx->m_cnt);
			my_mlx_pixel_put(&mlx->img, i + (VIEW / 2), j + (VIEW / 2), color);
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}


