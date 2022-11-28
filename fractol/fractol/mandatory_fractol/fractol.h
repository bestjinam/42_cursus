/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:31:23 by jinam             #+#    #+#             */
/*   Updated: 2022/11/28 21:36:53 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include "fractol_structure.h"
# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

# ifndef VIEW 
#  define VIEW 1000;
# endif

unsigned int	mb_get_color(int *xy, t_point *point, int line_len, int c);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color(int iter, int cnt);

#endif
