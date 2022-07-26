/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:29:54 by jinam             #+#    #+#             */
/*   Updated: 2022/07/26 10:36:03 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <string.h>

t_node	*_gnl_init_node(t_node **head, int fd)
{
	t_node	*curr;

	if (!*head)
	{
		*head = malloc(sizeof(t_node));
		if (!*head)
			return (0);
		(*head) -> fd = fd;
		(*head) -> buff_len = 0;
		(*head) -> next = (void *) 0;
	}
	curr = *head;
	while (curr && curr->fd != fd)
	{
		if (!curr->next)
		{
			curr->next = malloc(sizeof(t_node));
			if (!curr->next)
				return (0);
			curr->next->fd = fd;
			curr->next->buff_len = 0;
			curr->next->next = (void *) 0;
		}
		curr = curr->next;
	}
	return (curr);
}

size_t	_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*_gnl_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s2;
	unsigned char	*tmp_s1;

	if (!s1 && !s2)
		return (0);
	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		tmp_s1[i] = tmp_s2[i];
		i ++;
	}
	return (s1);
}

char	*_gnl_strdup(const char *str, size_t len)
{
	char	*res;
	size_t	s1_len;

	s1_len = len + 1;
	res = malloc(sizeof(char) * s1_len);
	if (!res)
		return (0);
	_gnl_memcpy(res, str, s1_len);
	res[len] = 0;
	return (res);
}

char	*_gnl_memjoin(char *s1, char *s2, size_t size)
{
	size_t	s1_len;
	char	*res;

	s1_len = _gnl_strlen(s1);
	res = malloc(sizeof(char) * (s1_len + size + 1));
	if (!res)
		return (0);
	_gnl_memcpy(res, s1, s1_len);
	free(s1);
	_gnl_memcpy(res + s1_len, s2, size + 1);
	res[s1_len + size] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static t_node	*node = NULL;
	t_node			*fd_node;
	char			*line;

	if (fd == -1)
		return (0);
	fd_node = _gnl_init_node(&node, fd);
	line = NULL;
	if (!fd_node->buff_len)
		fd_node->buff_len = read(fd, fd_node->buff, BUFFER_SIZE);
	while (fd_node->buff_len > 0)
	{
		if (!line)
			line = _gnl_strdup(fd_node->buff, fd_node->buff_len);
		else
			line = _gnl_memjoin(line, fd_node->buff, fd_node->buff_len);
		fd_node->buff_len = read(fd, fd_node->buff, BUFFER_SIZE);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	//int		fd2;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	//fd2 = open ("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("fd : %d\n", fd);
	printf("fd str: %s", str);

	//str = get_next_line(fd2);
	//printf("%s", str);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	printf("fd : %d\n", fd);
	str = get_next_line(fd);
	printf("fd str: %s", str);
	printf("fd : %d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);

}
