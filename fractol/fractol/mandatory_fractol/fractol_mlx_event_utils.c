/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_event_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:07:24 by jinam             #+#    #+#             */
/*   Updated: 2022/12/01 15:41:40 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	switch_imgnum(int x, int y, t_mlx *mlx)
{
	const long double	_x = (x - (double) VIEW / 2) * (mlx->pnt.width / VIEW);
	const long double	_y = (y - (double) VIEW / 2) * (mlx->pnt.height / VIEW);

	if (mlx->mouse_on == 1)
	{
		mlx->pnt.j_c_x = _x;
		mlx->pnt.j_c_y = _y;
		draw_julia(mlx);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_mlx *mlx)
{
	const long double	_x = (x - (double) VIEW / 2) * (mlx->pnt.width / VIEW);
	const long double	_y = (y - (double) VIEW / 2) * (mlx->pnt.height / VIEW);
	const t_frptr		fptr[3] = {draw_mandelbrot, draw_julia, draw_custom};

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
	else if (button == 2 && mlx->type == 1)
		mlx->mouse_on = 1;
	fptr[mlx->type](mlx);
	return (0);
}

int	mouseup_event(int botton, int x, int y, t_mlx *mlx)
{
	if (botton == 2)
		mlx->mouse_on = 0;
	return (0);
}

int	key_event(int keycode, t_mlx *mlx)
{
	const t_frptr	fptr[3] = {draw_mandelbrot, draw_julia, draw_custom};

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
