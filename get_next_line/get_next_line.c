/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:29:54 by jinam             #+#    #+#             */
/*   Updated: 2022/07/27 14:51:46 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <string.h>

static char	*_gnl_makeline(t_list *node, size_t size,
						char **line, size_t option)
{
	const size_t	res_len = node->last_len + size + 1;
	char			*res;

	res = malloc(sizeof(char) * (res_len));
	if (*line)
	{
		_gnl_memmove(res, *line, node->last_len);
		free(*line);
	}
	_gnl_memmove(&res[node->last_len],
		&node->buff[node->eol - size + 1], size + 1);
	res[res_len - 1] = 0;
	node->last_len += size;
	if (option == IS_END)
	{
		node->last_len = 0;
		node->eol ++;
	}
	node->new = 1;
	*line = res;
	return (res);
}

static void	_gnl_getline(int fd, t_list *node, size_t size)
{
	node->rbytes = read(fd, node->buff, size);
	node->eol = 0;
	node->new = 1;
}

char	*get_next_line(int fd)
{
	static t_list	node = {"", BUFFER_SIZE,
		BUFFER_SIZE, 0, 0}; //buff & rbytes & eol & last_len & new
	char			*line;

	line = (void *) 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL,0) < 0)
		return (0);

	while (1) //온전한 read가 되었을때까지만 돈다. -> while 빠져나온 마지막은eof
	{
		// 1234\n => read => return => gnl => read => bytes === 0 => return line = NULL;
		// prev = "123"; prev = ""; => return prev;
		if (node.eol == BUFFER_SIZE)
			_gnl_getline(fd, &node, BUFFER_SIZE); //read -> buffer  &  last_len ++ & start idx 초기화 & node.rbytes 갱신 
		if (node.rbytes == 0 || ((size_t)node.rbytes == node.eol))
			return (line);
		if (node.buff[node.eol] == '\n')
			return (_gnl_makeline(&node, node.new, &line, IS_END));
		//if (node.rbytes == BUFFER_SIZE && node.eol == BUFFER_SIZE - 1) //
		if (node.eol == (size_t)node.rbytes - 1)
			line = _gnl_makeline(&node, node.new, &line, NOT_END);
		node.eol ++;
		node.new ++;
	}
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("fd : %d\n", fd);
	printf("fd str: %s", str);
	str = get_next_line(fd);
	str = get_next_line(fd);
	printf("fd : %d\n", fd);
	printf("fd str: %s", str);*/
/*
str = get_next_line(fd);
	while (str)
	{
		printf("fd str: %s", str);
		str = get_next_line(fd);
	}
	close(fd);

} */
