/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:31:12 by jinam             #+#    #+#             */
/*   Updated: 2022/12/01 15:42:29 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	_init_mlx(t_mlx *mlx)
{
	mlx->size[0] = VIEW;
	mlx->size[1] = VIEW;
	mlx->m_cnt = 0;
	mlx->pnt.x = 0;
	mlx->pnt.y = 0;
	mlx->pnt.width = 4;
	mlx->pnt.height = 4;
	mlx->pnt.zoom_rate = 1;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, VIEW, VIEW, "fractol");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, VIEW, VIEW);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, \
					&mlx->img.line_len, &mlx->img.endian);
}

static void	_mangdelbrot_process(t_mlx *mlx)
{
	mlx->type = 0;
	draw_mandelbrot(mlx);
	mlx_mouse_hook(mlx->win, mouse_event, mlx);
	mlx_key_hook(mlx->win, key_event, mlx);
	mlx_loop(mlx->mlx_ptr);
}

static void	_julia_process(t_mlx *mlx)
{
	mlx->type = 1;
	draw_julia(mlx);
	mlx_hook(mlx->win, 6, 0, switch_imgnum, mlx);
	mlx_hook(mlx->win, 5, 0, mouseup_event, mlx);
	mlx_mouse_hook(mlx->win, mouse_event, mlx);
	mlx_key_hook(mlx->win, key_event, mlx);
	mlx_loop(mlx->mlx_ptr);
}


static void	_custom_process(t_mlx *mlx)
{
	mlx->type = 2;
	draw_custom(mlx);
	mlx_mouse_hook(mlx->win, mouse_event, mlx);
	mlx_key_hook(mlx->win, key_event, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
	{
		ft_printf("./fractol [fractol]\n 1. mangdelbrot\n");
		ft_printf("2. julia\n 3. custom\n");
		return (1);
	}
	_init_mlx(&mlx);
	if (ft_strncmp("mangdelbrot", argv[1], ft_strlen(argv[1])) == 0)
		_mangdelbrot_process(&mlx);
	if (ft_strncmp("julia", argv[1], ft_strlen(argv[1])) == 0)
		_julia_process(&mlx);
	if (ft_strncmp("custom", argv[1], ft_strlen(argv[1])) == 0)
		_custom_process(&mlx);
	return (0);
}
