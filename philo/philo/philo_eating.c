/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:35:47 by jinam             #+#    #+#             */
/*   Updated: 2023/02/09 13:46:06 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>
#include <stdio.h>
#include "philo.h"
#include <unistd.h>

int	_grep_fork(t_args *args, t_fork *fork)
{
	while (1)
	{
		pthread_mutex_lock(&args->active_mx);
		if (args->active == DEAD)
		{
			pthread_mutex_unlock(&args->active_mx);
			return (DEAD);
		}
		pthread_mutex_unlock(&args->active_mx);
		pthread_mutex_lock(&fork->fork_mt);
		if (fork->fork_st == UNAVAIL)
			pthread_mutex_unlock(&fork->fork_mt);
		else
			break ;
	}
	fork->fork_st = UNAVAIL;
	pthread_mutex_unlock(&fork->fork_mt);
	return (LIVE);
}

int	_preparing_forks(t_philo_info *philo)
{
	t_fork	*first;
	t_fork	*last;
	int		ret;

	first = philo->r_fork;
	last = philo->l_fork;
	if (!philo->id % 2)
	{
		first = philo->l_fork;
		last = philo->r_fork;
	}
	ret = _grep_fork(philo->args, first);
	if (ret != DEAD)
		ret = _grep_fork(philo->args, last);
	return (ret);
}

void	_releasing_forks(t_philo_info *philo)
{
	pthread_mutex_lock(&philo->l_fork->fork_mt);
	philo->l_fork->fork_st = AVAIL;
	pthread_mutex_unlock(&philo->l_fork->fork_mt);
	pthread_mutex_lock(&philo->r_fork->fork_mt);
	philo->r_fork->fork_st = AVAIL;
	pthread_mutex_unlock(&philo->r_fork->fork_mt);
}

int	philo_eating(t_philo_info *philo)
{
	int	ret;

	ret = _preparing_forks(philo);
	if (ret == DEAD)
		return (ret);
	philo_printf(philo, "is eating\n");
	philo->eats ++;
	ft_usleep(philo->args->argv[2]);
	pthread_mutex_lock(&philo->leat_mx);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(&philo->leat_mx);
	pthread_mutex_lock(&philo->args->print_mx);
	printf("id : %d %ld %d\n", philo->id, philo->last_eat.tv_sec, philo->last_eat.tv_usec);
	pthread_mutex_unlock(&philo->args->print_mx);
	_releasing_forks(philo);
	ret = LIVE;
	pthread_mutex_lock(&philo->args->active_mx);
	if (philo->args->active == DEAD)
		ret = DEAD;
	pthread_mutex_unlock(&philo->args->active_mx);
	return (ret);
}
