/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_section.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:08 by jinam             #+#    #+#             */
/*   Updated: 2023/02/01 20:33:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*count(void *arg);
int	cnt = 0;

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, count, (void *)"thread1");
	pthread_create(&thread2, NULL, count, (void *)"thread2");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}

void	*count(void *arg)
{
	int			i;
	const char	*name = (const char *)arg;
	
	//CRITICAL_SECTION
	i = 0;
	while (i < 300)
	{
		printf("%s cnt : %d\n", name, ++cnt);
		//usleep(1);
		i ++;
	}
	//CRITICAL_SECTION
	return(NULL);
}
