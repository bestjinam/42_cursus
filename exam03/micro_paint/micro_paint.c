#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_zone
{
	int		w;
	int		h;
	char	bg;
}	t_zone;

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

t_zone	g_zone;
t_draw	g_draw;
char	**g_tab;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_exit(int err)
{
	int	i;

	if (err != 0)
	{
		if (err == 1)
			ft_putstr("Error: argument\n");
		else if (err == 2)
			ft_putstr("Error: Operation file corrupted\n");
		else if (err == 3)
		{
			ft_putstr("Error: Operation file corrupted\n");
			i = -1;
			while (g_tab[++i])
				free(g_tab[i]);
			free(g_tab);
		}
		return (1);
	}
	return (0);
}

int	init_zone(FILE *fp)
{
	if (fscanf(fp, "%d %d %c\n", &g_zone.w, &g_zone.h, &g_zone.bg) != 3)
		return (-1);
	if (g_zone.w <= 0 || g_zone.w > 300)
		return (-1);
	if (g_zone.h <= 0 || g_zone.h > 300)
		return (-1);
	return (0);
}

void	init_tab(void)
{
	int	i;

	g_tab = malloc(sizeof(char *) * (g_zone.h + 1));
	g_tab[g_zone.h] = 0;
	i = 0;
	while (i < g_zone.h)
	{
		g_tab[i] = malloc(sizeof(char) * (g_zone.w + 1));
		g_tab[i][g_zone.w] = 0;
		memset(g_tab[i], g_zone.bg, g_zone.w);
		i ++;
	}
}

int	is_it(float x, float y)
{
	if ((x < g_draw.x || x > g_draw.x2) || (y < g_draw.y || y > g_draw.y2))
		return (-1);
	else if (g_draw.r == 'R')
		return (0);
	else if (g_draw.r == 'r' && ((x - g_draw.x < 1.0f || g_draw.x2 - x < 1.0f) || (y - g_draw.y< 1.0f || g_draw.y2 - y < 1.0f)))
		return (0);
	return (-1);
}

void	drawing_shape(void)
{
	int	y;
	int	x;

	y = 0;
	while (y < g_zone.h)
	{
		x = 0;
		while (x < g_zone.w)
		{
			if (is_it((float) x, (float) y) == 0)
				g_tab[y][x] = g_draw.c;
			x ++;
		}
		y ++;
	}
}

int	read_shapes(FILE *fp)
{
	int	tmp;

	tmp = fscanf(fp, "%c %f %f %f %f %c\n", &g_draw.r, &g_draw.x, &g_draw.y, &g_draw.w, &g_draw.h, &g_draw.c);
	while (tmp == 6)
	{
		if ((g_draw.w <= 0) || (g_draw.h <= 0) || (g_draw.r != 'r' && g_draw.r != 'R'))
			return (-1);
		g_draw.x2 = g_draw.x + g_draw.w;
		g_draw.y2 = g_draw.y + g_draw.h;
		drawing_shape();
		tmp = fscanf(fp, "%c %f %f %f %f %c\n", &g_draw.r, &g_draw.x, &g_draw.y, &g_draw.w, &g_draw.h, &g_draw.c);
	}
	if (tmp != EOF)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	FILE	*fp;
	int		i;

	fp = NULL;
	if (argc != 2)
		return (ft_exit(1));
	fp = fopen(argv[1], "r");
	if (!fp)
		return (ft_exit(2));
	if (init_zone(fp) == -1)
		return (ft_exit(2));
	init_tab();
	if (read_shapes(fp) == -1)
		return (ft_exit(3));
	i = -1;
	while (g_tab[++i])
	{
		ft_putstr(g_tab[i]);
		ft_putstr("\n");
		free(g_tab[i]);
	}
	free(g_tab);
	return (0);
}
