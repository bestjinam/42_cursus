/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:49:31 by jinam             #+#    #+#             */
/*   Updated: 2022/07/27 09:38:11 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define	BUFFER_SIZE 20
int main(void)
{
	char	buf[BUFFER_SIZE	+ 1];
	int		fd;
	int		temp_read_size = 0;

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		while ((temp_read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			printf("read_size : %d\n", temp_read_size);
			for (int j = 0 ; j < BUFFER_SIZE ; j++)
				printf("%c", buf[j]);
			printf("\n");
			printf("str: %s", buf);
			//memset(buf, 0, BUFFER_SIZE);
		}
		temp_read_size = read(fd, buf, BUFFER_SIZE);
		{
			printf("read_size : %d\n", temp_read_size);
			for (int j = 0 ; j < BUFFER_SIZE ; j++)
				printf("%c", buf[j]);
			printf("\n");
			printf("str: %s", buf);
			//memset(buf, 0, BUFFER_SIZE);
		}

		close(fd);
	}
	return (0);
}
