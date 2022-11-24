/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:07:51 by jinam             #+#    #+#             */
/*   Updated: 2022/11/24 17:29:56 by jinam            ###   ########.fr       */
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

void	draw_circle(t_data *img, int *size)
{
	int			i;
	int			j;
	const int	center[2] = {size[0] / 2, size[1] / 2}; 
	const int	circle_r = get_distance(center[0], size[1], (int *) &center);

	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			if (get_distance(i, j, (int *)&center) <= circle_r)
				my_mlx_pixel_put(img, i, j, 0x00FF0000);
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
	draw_circle(&img, (int *)&size);
	printf("line length : %d\n", img.line_length);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
