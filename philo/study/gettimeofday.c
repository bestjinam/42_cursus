/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:24:30 by jinam             #+#    #+#             */
/*   Updated: 2023/02/01 12:08:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	time_t			t;
	struct tm		*lt;
	struct timeval	tv;

	if ((t = gettimeofday(&tv, NULL)) == -1)
	{
		perror("gettimeofday() call error");
		return (-1);
	}
	if ((lt = localtime(&tv.tv_sec)) == NULL)
	{
		perror("localtime () call error");
		return (-1);
	}
	printf("current time : %04d-%02d-%02d %02d:%02d:%02d.%06d\n", \
			lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, 
			lt-> tm_min, lt->tm_sec, tv.tv_usec);
	return (0);
}
