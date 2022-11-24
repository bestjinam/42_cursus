/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_many_circles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:07:51 by jinam             #+#    #+#             */
/*   Updated: 2022/11/24 18:17:05 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_test.h"

int	get_offset_img(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + get_offset_img(x, y, data->line_length, data->bits_per_pixel);
	*(unsigned int *) dst = color;
}

int	ft_sqrt(int nb)
{
	long long	i;

	i = 0;
	while (i * i < nb)
		i ++;
	return (i);
}

int	get_distance(int x, int y, int *center)
{
	int	square_res;

	square_res = (x - center[0]) * (x - center[0]) + (y - center[1]) * (y - center[1]); 
	return (ft_sqrt(square_res));
}

void	draw_circle(t_data *img, int *center, int len, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < center[0] * 2)
	{
		j = 0;
		while (j < center[1] * 2)
		{
			if (get_distance(i, j, center) <= len)
				my_mlx_pixel_put(img, i, j, color);
			j ++;
		}
		i ++;
	}
}

#include <stdio.h>

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	const int	size[2] = {800, 800};
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, size[0], size[1], "hello world");
	img.img = mlx_new_image(mlx, size[0], size[1]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, \
			&img.endian);
	printf("line length : %d\n", img.line_length);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 400, 0x00FFB1B0);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 350, 0x00ffdfbe);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 300, 0x00ffffbf);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 250, 0x00b4f0a7);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 200, 0x00a9d1f7);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 150, 0x00cc99ff);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 100, 0x00ffffff);
	draw_circle(&img, (int [2]){size[0] / 2, size[1] / 2}, 50, 0x00000000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
