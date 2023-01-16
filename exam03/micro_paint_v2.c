/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:47:20 by jinam             #+#    #+#             */
/*   Updated: 2023/01/16 20:11:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	H;
int	W;
char	BG;
char	**TAB;

int i;
int	j;
int	line;
int	col;

typedef struct	s_draw
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

int	is_in_rect(int x, int y, t_draw el)
{
	if ((x - el.x < 1.0f) || (el.x2 - x < 1.0f) \
			|| (y -el.y < 1.0f) || (el.y2 - y < 1.0f))
		return (1);
	else
		return (0);
}

int	err_msg(FILE *fd, int err)
{
	if (err == 2)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		err = 1;
	}
	else if (err == 1)
		write(1, "Error: argument\n", 16);
	else
	{
		i = 0;
		while (i < H)
		{
			write(1, TAB[i], W);
			write(1, "\n", 1);
			i ++;
		}
	}
	if (fd)
		fclose(fd);
	if (TAB)
	{
		i = 0;
		while (i < H)
		{
			free(TAB[i]);
			i ++;
		}
	}
	return (err);
}

int	validate_input(FILE *fd, int res)
{
	if (!fd || res != 3)
		return (0);
	else
	{
		if (W > 0 && W <= 300 && H > 0 && H <= 300)
			return (1);
		else
			return (0);
	}
}

int	main(int ac, char **av)
{
	FILE	*fd;
	int		res;
	t_draw	el;
	
	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	fd = fopen(av[1], "r");
	res = fscanf(fd, "%d %d %c", &W, &H, &BG);
	if (validate_input(fd, res))
	{
		TAB = malloc(H * sizeof(char *));
		i = 0;
		while (i < H)
		{
			TAB[i] = malloc(W * sizeof(char));
			memset(TAB[i], BG, W);
			i ++;
		}
		while (1)
		{
			res = fscanf(fd, "\n%c %f %f %f %f %c", &el.r, &el.x, &el.y, &el.w, &el.h, &el.c);
			if (res == EOF)
				return (err_msg(fd, 0));
			else if (res != 6 || el.w <= 0 || el.h <= 0 || (el.r != 'r' && el.r != 'R'))
				break ;
			el.x2 = el.x + el.w;
			el.y2 = el.y + el.h;
			line = 0;
			while (line < H)
			{
				col = 0;
				while (col < W)
				{
					if (line >= el.y && el.y2 >= line && col >= el.x && el.x2 >= col)
					{
						if (el.r == 'R' || (el.r == 'r' && is_in_rect(col, line, el)))
							TAB[line][col] = el.c;
					}
					col ++;
				}
				line ++;
			}
		}
	}
	err_msg(fd, 2);
}

















