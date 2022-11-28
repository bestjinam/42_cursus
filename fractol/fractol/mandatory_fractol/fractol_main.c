/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:31:12 by jinam             #+#    #+#             */
/*   Updated: 2022/11/28 21:46:15 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	_init_mlx(t_mlx *mlx, t_point *point)
{
	mlx->size[0] = VIEW;
	mlx->size[1] = VIEW;
	point->x = 0;
	point->y = 0;
	point->width = 4;
	point->height = 4;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "fractol");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, \
					&mlx->img.line_len, &mlx->img.endian);
}

static void	_mangdelbrot_process(t_mlx *mlx, t_point *point)
{
	int	i;
	int	j;
	int	color;
	int	cnt;

	i = -500; 
	cnt = 0;
	while (i < 500)
	{
		j = -500;
		while (j < 500)
		{
			color = mb_get_color((int []){i, j}, point, 500, cnt);
			my_mlx_pixel_put(&mlx->img, i + 500, j + 500, color);	
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_point	point;

	if (argc < 2)
	{
		ft_printf("./fractol [fractol]\n 1. mangdelbrot\n");
		ft_printf("2. julia\n 3. custom\n");
		return (1);
	}
	_init_mlx(&mlx, &point);
	if (ft_strncmp("mangdelbrot", argv[1], ft_strlen(argv[1])))
		_mangdelbrot_process(&mlx, &point);	
	return (0);
}
