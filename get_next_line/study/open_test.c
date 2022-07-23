/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:22:29 by jinam             #+#    #+#             */
/*   Updated: 2022/07/23 14:24:45 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (void)
{
	int fd;

	fd = open ("test.txt", O_RDONLY);
	if (fd < 1)
	{
		printf("open () error");
		exit(1);
	}
	printf("fd : %d\n", fd);
	close(fd);
	return (0);
}
