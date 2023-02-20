/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:14:09 by jinam             #+#    #+#             */
/*   Updated: 2023/02/19 17:07:18 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <string.h>

int	_init_args(int argc, t_args *args, char **argv)
{
	int	i;

	if (argc < 4 || argc > 5)
		return (FEW_ARGS);
	i = 1;
	while (i < argc + 1)
	{
		if (!str_is_digit(argv[i]) || ft_atoi(argv[i]) < 0)
			return (INVALID);
		i ++;
	}
	args->argc = argc;
	args->num = ft_atoi(argv[1]);
	args->die_t = ft_atoi(argv[2]);
	args->eat_t = ft_atoi(argv[3]);
	args->sleep_t = ft_atoi(argv[4]);
	args->eat_cnt = 0;
	if (argc == 5)
		args->eat_cnt = ft_atoi(argv[5]);
	if (args->num == 0 || (argc == 5 && args->eat_cnt == 0))
		return (INVALID);
	return (SUCCESS);
}

int	_init_table(int argc, t_watchdog *watchdog, t_speaker *speaker)
{
	if (pthread_mutex_init(&watchdog->active_mt, NULL) || \
			pthread_mutex_init(&watchdog->ready_mt, NULL) || \
			pthread_mutex_init(&speaker->print_mt, NULL))
		return (MALLOC_FAIL);
	speaker->print = AVAIL;
	watchdog->active = ALIVE;
	if (argc == 5)
	{
		watchdog->full = 0;
		if (pthread_mutex_init(&watchdog->full_mt, NULL))
			return (MALLOC_FAIL);
	}
	return (SUCCESS);
}

int	_destroy_table(int err, t_room *room)
{
	int	res;
	int	i;

	res = SUCCESS;
	if (err == MALLOC_FAIL)
		res = FAIL;
	pthread_mutex_destroy(&room->watchdog.active_mt);
	pthread_mutex_destroy(&room->watchdog.ready_mt);
	pthread_mutex_destroy(&room->speaker.print_mt);
	if (room->args.argc == 5)
		pthread_mutex_destroy(&room->watchdog.full_mt);
	if (room->victims)
	{
		i = -1;
		while (++i < room->args.num)
		{
			pthread_mutex_destroy(&room->victims[i].eats_mt);
			pthread_mutex_destroy(&room->victims[i].last_mt);
			if (room->forks)
				pthread_mutex_destroy(&room->forks[i].fork_mt);
		}
		free(room->victims);
	}
	free(room->forks);
	return (res);
}

int	_init_room(int argc, char **argv, t_room *room)
{
	int	tmp;

	memset(room, 0, sizeof(t_room));
	tmp = _init_args(argc, &room->args, &argv[0]);
	if (tmp != SUCCESS)
		return (philo_err_exit(tmp));
	tmp = _init_table(argc, &room->watchdog, &room->speaker);
	if (tmp == MALLOC_FAIL)
		return (_destroy_table(tmp, room));
	room->victims = malloc(sizeof(t_philo) * room->args.num);
	room->forks = malloc(sizeof(t_fork) * room->args.num);
	if (!room->victims || !room->forks)
		return (_destroy_table(MALLOC_FAIL, room));
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_room	room;
	int		res;

	res = _init_room(argc - 1, argv, &room);
	if (res != SUCCESS)
		return (1);
	res = run_philo_game(&room);
	if (res == FAIL)
		return (_destroy_table(res, &room));
}
