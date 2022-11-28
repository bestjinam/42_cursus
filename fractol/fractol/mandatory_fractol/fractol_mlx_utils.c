/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:07:24 by jinam             #+#    #+#             */
/*   Updated: 2022/11/28 21:33:49 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(int iter, int cnt)
{
	const int	r[4][5] = {{0xf72585, 0x7209b7, 0x3a0ca3, 0x4361ee, 0x4cc9f0}, \
					{0xb0b0b0, 0x939191, 0x8c8b8b, 0x7f7e7e, 0x727272}, \
					{0x006575, 0x007d83, 0xb7b390, 0x5e8767, 0x4c6b53}, \
					{0x83704c, 0xaf9665, 0xdbbc7f, 0xe2c998, 0xe9d6b2}};
	if (iter == 1000)
		return (0x00000000);
	return (r[cnt % 4][iter % 5]);
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

