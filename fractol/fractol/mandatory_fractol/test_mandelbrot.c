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
int	get_offset_img(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + get_offset_img(x, y, img->line_len, \
									img->bpp);
	*(unsigned int *) dst = color;
}
unsigned int	get_tmp_color(int *xy, int line_len)
{
	long double	x[3];
	long double y[2];
	int			iter;

	iter = 0;
	x[0] = xy[0] * ((double) 4 / line_len);
	y[0] = xy[1] * ((double) 4 / line_len);
	x[1] = 0;
	y[1] = 0;
	while ((x[1] * x[1] + y[1] * y[1] <= 2 * 2) && (iter < 100))
	{
		x[2] = x[1] * x[1] - y[1] * y[1] + x[0];
		y[1] = 2 * x[1] * y[1] + y[0];
		x[1] = x[2];
		iter ++;
	}
	if (iter == 100)
		return (0xff000000);
	if (iter % 2 == 0)
		return (0xf72585);
	if (iter % 3 == 0)
		return (0x7209b7);
	else
		return (0x4361ee);
}

static void draw(t_mlx *mlx)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < VIEW / 2)
	{
		j = 0;
		while (j < VIEW /2)
		{
			color = get_tmp_color((int []){i - (VIEW / 2), j - (VIEW / 2)}, VIEW);
			my_mlx_pixel_put(&mlx->img, i + (VIEW / 2), j + (VIEW / 2), color);
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

static void	test_process(t_mlx *mlx)
{
	draw(mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	_init_mlx(&mlx);
	test_process(&mlx);
	return (0);
}
