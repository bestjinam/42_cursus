/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gotchi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:38:53 by jinam             #+#    #+#             */
/*   Updated: 2023/02/15 21:35:55 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

// a(micro) = 500;
// eat_time 200 sleep 60 die 400 -> 홀 : 140 + a
// eat_time 200 sleep 200 die 400 -> 홀 : a  

void	*philo_gotchi(void *raw)
{
	t_philo	*victim;

	victim = (t_philo *)raw;
	pthread_mutex_lock(&victim->jigsaw->ready_mt);
	pthread_mutex_unlock(&victim->jigsaw->ready_mt);
	if (victim->id % 2)
		usleep(800);
	while (1)
	{
		if (philo_eating(victim) == DEAD)
			break ;
		if (victim->args->argc == 5 && victim->eats == 0)
			break ;
		if (philo_sleeping(victim, victim->args->sleep) == DEAD)
			break ;
		// gap 계산 eat > sleep -> eat -sleep
		if (philo_thinking(victim, ))
	}
}
