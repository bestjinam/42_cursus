/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jigsaw_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:12:08 by jinam             #+#    #+#             */
/*   Updated: 2023/02/17 13:36:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

int	jigsaw_watch(struct timeval last)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec - last.tv_sec) * 1000 \
			+ ((curr.tv_usec / 1000 - last.tv_usec / 1000)));
}

void	jigsaw_printf(int id, t_sys_info *jigsaw, char *str)
{
	pthread_mutex_lock(&jigsaw->print_mt);
	if (jigsaw->print == AVAIL)
		printf("%d %d %s", jigsaw_watch(jigsaw->start), id, str);
	pthread_mutex_lock(&jigsaw->print_mt);
}
