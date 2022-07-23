/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:01:12 by jinam             #+#    #+#             */
/*   Updated: 2022/07/23 17:23:40 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1

int main(void)
{
	char	buf[BUFFER_SIZE + 1];
	char	*save;
	int		fd;
	int		temp_read_size = 0;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		while ((temp_read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[temp_read_size] = '\0';
			if (save == NULL)
				save = strdup(buf);
			else
				strcat(save, buf);
		}
		printf("%s", save);
		close(fd);
	}
	return 0;
}
