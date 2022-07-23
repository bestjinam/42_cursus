/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:49:31 by jinam             #+#    #+#             */
/*   Updated: 2022/07/23 16:51:38 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	buf[100];

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		read(fd, buf, sizeof(buf));
		printf("%s\n", buf);
		close(fd);
	}
	return 0;
}
