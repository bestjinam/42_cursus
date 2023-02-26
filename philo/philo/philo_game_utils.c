/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:19:11 by jinam             #+#    #+#             */
/*   Updated: 2023/02/20 15:35:13 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	checking_vital(t_watchdog *watchdog)
{
	int	res;

	res = ALIVE;
	pthread_mutex_lock(&watchdog->active_mt);
	if (watchdog->active == DEAD)
		res = DEAD;
	pthread_mutex_unlock(&watchdog->active_mt);
	return (res);
}

int	philo_watch(struct timeval start)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec - start.tv_sec) * 1000 \
			+ ((curr.tv_usec / 1000 - start.tv_usec / 1000)));
}

void	speaker_printf(t_philo *vct, char *str)
{
	pthread_mutex_lock(&vct->speaker->print_mt);
	if (vct->speaker->print == AVAIL)
		printf("%d %d %s", philo_watch(vct->watchdog->start), vct->id, str);
	pthread_mutex_unlock(&vct->speaker->print_mt);
}
