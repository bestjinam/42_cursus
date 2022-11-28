/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:58:29 by jinam             #+#    #+#             */
/*   Updated: 2022/11/26 15:43:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_test.h"

int	get_offset_img(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + get_offset_img(x, y, data->line_length, \
									data->bits_per_pixel);
	*(unsigned int *) dst = color;
}

void	single_pixel_put(t_data *img, int x, int y)
{
	int		r;
	int		g;
	int		b;
	int		rgb_color;
	char	*dst;


	r = (int)(255 * ((double) x / (800 - 1)));
	g = (int)(255 * ((double) y / (800 - 1)));
	b = (int)(255 * 0.25);
	rgb_color = (r << 16) | (g << 8) | b;
	my_mlx_pixel_put(img, x, y, rgb_color);
}

void	draw_rainbow_box(t_data *img, int *size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size[0])
	{
		j = 0;
		while (j < size[1])
		{
			single_pixel_put(img, i, j);
			j ++;
		}
		i ++;
	}
}

int	main(void)
{
	t_mlx_instance	mlx;
	t_data			img;
	const int		size[2] = {800, 800};
	
	mlx.mlx_instance = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_instance, size[0], size[1], "ex02");
	img.img = mlx_new_image(mlx.mlx_instance, size[0], size[1]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	draw_rainbow_box(&img, (int *) size);
	mlx_put_image_to_window(mlx.mlx_instance, mlx.mlx_win, img.img, 0, 0);
	mlx_loop(mlx.mlx_instance);
}
