/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:01:44 by jinam             #+#    #+#             */
/*   Updated: 2023/02/04 19:03:33 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <string.h>
#include "philo.h"
#include <unistd.h>
#include <stdlib.h>

int	init_argvs(int argc, t_args *args, char **argv)
{
	int	i_idx;

	memset(args, 0, sizeof(t_args));
	if (gettimeofday(&args->start, NULL) == -1)
		return (-2);
	pthread_mutex_init(&args->print_mx, NULL);
	pthread_mutex_init(&args->active_mx, NULL);
	args->argv = malloc(argc * sizeof(int));
	if (!args->argv)
		return (-1);
	i_idx = 0;
	while (argv[i_idx])
	{
		if (!_str_is_digit(argv[i_idx]))
		{
			free(args->argv);
			return (-1);
		}
		args->argv[i_idx] = ft_atoi(argv[i_idx]);
		i_idx ++;
	}
	args->argc = argc - 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_system_info	_sys;
	int				tmp;

	if (argc < 5 || argc > 6)
		return (philo_main_exit());
	tmp = init_argvs(argc, &_sys.args, &argv[1]);
	if (tmp != 0)
	{
		if (tmp == -1)
			write(2, "numeric argument required\n", 27);
		else if (tmp == -2)
			write(2, "gettimeofday() call error\n", 26);
		return (philo_main_exit());
	}
	tmp = run_philo_tycoon(&_sys);
	return (0);
}
