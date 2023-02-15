/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:49:18 by jinam             #+#    #+#             */
/*   Updated: 2023/02/13 21:04:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <math.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_args
{
	int		h;
	int		w;
	char	bg;
	char	**tab;
}	t_args;

typedef struct s_draw
{
	char	r;
	float	x;
	float	y;
	float	x2;
	float	y2;
	float	w;
	float	h;
	char	c;
}	t_draw;

#endif
