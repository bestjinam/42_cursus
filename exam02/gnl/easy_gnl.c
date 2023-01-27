/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:53:29 by jinam             #+#    #+#             */
/*   Updated: 2023/01/17 13:40:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# undef BUFFER_SIZE 
#endif 

# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}


char	*buff_copy(char	*res, char c)
{
	int		res_len;
	char	*line;
	int		i;

	if (!res)
	{
		line = malloc(2);
		line[0] = c;
		line[1] = 0;
		return (line);
	}
	res_len = ft_strlen(res) + 1; 
	line = malloc(res_len + 1);
	i = 0;
	while (res[i])
	{
		line[i] = res[i];
		i ++;
	}
	line[i] = c;
	line[i + 1] = 0;
	free(res);
	return (line);
}


char	*get_next_line(int fd)
{
	char	*line;
	char	buf;
	int		rbytes;

	buf = 0;
	rbytes = BUFFER_SIZE;
	line = 0;
	while (buf != '\n' && rbytes != 0)
	{
		rbytes = read(fd, &buf, BUFFER_SIZE);
		if (rbytes)
			line = buff_copy(line, buf);
	}
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*rs;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	rs = get_next_line(fd);
	while (rs)
	{
		printf("%s", rs);
		rs = get_next_line(fd);
	}
	return (0);
}
