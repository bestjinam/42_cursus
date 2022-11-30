/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:07:24 by jinam             #+#    #+#             */
/*   Updated: 2022/11/30 19:49:29 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

unsigned int	get_color(int iter, int cnt)
{
	const int	r[4][5] = {{0xf72585, 0x7209b7, 0x3a0ca3, 0x4361ee, 0x4cc9f0}, \
					{0xb0b0b0, 0x939191, 0x8c8b8b, 0x7f7e7e, 0x727272}, \
					{0x006575, 0x007d83, 0xb7b390, 0x5e8767, 0x4c6b53}, \
					{0x83704c, 0xaf9665, 0xdbbc7f, 0xe2c998, 0xe9d6b2}};

	if (iter == 100)
		return (0x00000000);
	return (r[cnt % 4][iter % 5]);
}

int	get_offset_img(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

int	mouse_event(int button, int x, int y, t_mlx *mlx)
{
	const long double	_x = (x - (double) VIEW / 2) * (mlx->pnt.width / VIEW);
	const long double	_y = (y - (double) VIEW / 2) * (mlx->pnt.height / VIEW);
	const t_fractol_funcptr	fptr[2] = {draw_mandelbrot, draw_julia};

	if (button == 1)
		mlx->m_cnt ++;
	else if (button == 4)
	{
		mlx->pnt.x += _x * 0.1;
		mlx->pnt.y += _y * 0.1;
		mlx->pnt.height *= 0.9;
		mlx->pnt.width *= 0.9;
	}
	else if (button == 5)
	{
		mlx->pnt.x -= _x * 1 / 9.;
		mlx->pnt.y -= _y * 1 / 9.;
		mlx->pnt.height *= (double) 10 / 9;
		mlx->pnt.width *= (double) 10 / 9;
	}
	else if (button == 2)
	{
		mlx->pnt.j_c_x = _x;
		mlx->pnt.j_c_y = _y;
	}
	fptr[mlx->type](mlx);
	return (0);
}

int	key_event(int keycode, t_mlx *mlx)
{	
	const t_fractol_funcptr	fptr[2] = {draw_mandelbrot, draw_julia};
	
	if (keycode == ESC)
		exit(0);
	else
	{
		if (keycode == RIGHT)
			mlx->pnt.x += mlx->pnt.width * 0.1;
		else if (keycode == LEFT)
			mlx->pnt.x -= mlx->pnt.width * 0.1;
		else if (keycode == UP)
			mlx->pnt.y -= mlx->pnt.height * 0.1;
		else if (keycode == DOWN)
			mlx->pnt.y += mlx->pnt.height * 0.1;
		else if (keycode == RESET)
		{
			mlx->pnt.x = 0;
			mlx->pnt.y = 0;
			mlx->pnt.height = 4;
			mlx->pnt.width = 4;
		}
		fptr[mlx->type](mlx);
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + get_offset_img(x, y, img->line_len, \
									img->bpp);
	*(unsigned int *) dst = color;
}
