/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:30:12 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 12:51:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

char	*get_next_lie(int fd);

typedef enum e_eof
{
	IS_END,
	NOT_END,
	READ_ERROR
}	t_eof;

typedef struct	s_list
{
	char	buff[BUFFER_SIZE];
	ssize_t	rbytes;
	size_t	eol;
	size_t	last_len;
	size_t	new_len;
}	t_list;

static void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	if (!s1 && !s2)
		return (0);
	t_s1 = (unsigned char *) s1;
	t_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		t_s1[i] = t_s2[i];
		i ++;
	}
	return (s1);
}

static void	*_gnl_clear(t_list *node, char *line)
{
	if (line)
		free(line);
	node->eol = BUFFER_SIZE;
	node->last_len = 0;
	return (NULL);
}

static void	_gnl_get_line(int fd, t_list *node, size_t size)
{
	node->rbytes = read(fd, node->buff, size);
	node->eol = 0;
	node->new_len = 1;
}

static char	*_gnl_makeline(t_list *node, size_t new_len, char **line, size_t opt) 
{
	const size_t	res_len = node->last_len + new_len + 1;
	char			*res;

	res = malloc(sizeof(char) * (res_len));
	if (!res)
		return (NULL);
	if (*line)
	{
		ft_memcpy(res, *line, node->last_len);
		free(*line);
	}
	ft_memcpy(&res[node->last_len], &node->buff[node->eol - new_len + 1], new_len + 1);
	res[res_len - 1] = 0;
	node->last_len += new_len;
	if (opt == IS_END)
	{
		node->last_len = 0;
		node->eol ++;
	}
	node->new_len = 1;
	*line = res;
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	node = {"", BUFFER_SIZE, BUFFER_SIZE, 0, 0};
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (_gnl_clear(&node, line));
	while (1)
	{
		if (node.eol == BUFFER_SIZE)
			_gnl_get_line(fd, &node, BUFFER_SIZE);
		if (node.rbytes <= 0 || ((size_t)node.rbytes == node.eol))
		{
			_gnl_clear(&node, NULL);
			return (line);
		}
		if (node.buff[node.eol] == '\n')
			return (_gnl_makeline(&node, node.new_len, &line, IS_END));
		if (node.eol == (size_t)node.rbytes - 1)
			line = _gnl_makeline(&node, node.new_len, &line, NOT_END);
		node.eol ++;
		node.new_len ++;
	}
}
