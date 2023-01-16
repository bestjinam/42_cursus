/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:11:20 by jinam             #+#    #+#             */
/*   Updated: 2023/01/16 14:00:05 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		W;
int		H;
char	BG;
char	**TAB;

typedef struct draw
{
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
}	Draw;

int	err_msg(FILE *fd, int err)
{
	int	i;
	int	j;

	if (err == 2 && (err = 1))
		write(1, "Error: Operation file corrupted\n", 32);
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
		j = 0;
		while (j < H)
		{
			free(TAB[j]);
			j ++;
		}
	}
	return (err);
}

int	main(int ac, char **av)
{
	FILE	*fd;
	float	sqr;
	int		res;
	Draw	el;
	int		i;
	int		line;
	int		col;

	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	fd = fopen(av[1], "r");
	if (fd)
	{
		res = fscanf(fd, "%d %d %c", &W, &H, &BG);
		if (res == 3)
		{
			if ((W > 0 && W <= 300) && (H > 0 && H <= 300))
			{
				TAB = malloc(H *sizeof(char *));
				i = 0;
				while (i < H)
				{
					TAB[i] = malloc(W *sizeof(char));
					memset(TAB[i], BG, W);
					i ++;
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %c", &el.t, &el.x, &el.y, &el.r, &el.c);
					if (res == EOF)
						return (err_msg(fd, 0));
					else if (res != 5 || el.r <= 0 || (el.t != 'C' && el.t != 'c'))
						break ;
					line = 0;
					while (line < H)
					{
						col = 0;
						while (col < W)
						{
							sqr = sqrtf(powf(line - el.y, 2.0) + powf(col - el.x, 2.0));
							if (sqr <= el.r)
							{
								if ((el.t == 'C') || (el.t == 'c' && el.r - sqr < 1.0f))
									TAB[line][col] = el.c;
							}
							col ++;
						}
						line ++;
					}
				}
				
			}
		}
	}
	return (err_msg(fd, 2));
}
