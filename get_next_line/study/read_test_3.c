/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:43:21 by jinam             #+#    #+#             */
/*   Updated: 2022/07/23 18:52:56 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	char	*save;
	int		fd;
	int		read_size = 0;

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[read_size] = 0;
			if (save == NULL)
				save = strdup(buf);
			else
				strcat(save, buf);
		}
		printf("%s", save);
		close(fd);
	}
	return (0);
}
