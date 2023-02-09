/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:11:13 by jinam             #+#    #+#             */
/*   Updated: 2023/02/09 14:13:12 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	struct timeval		start;
	int					*argv;
	int					argc;
	int					active;
	pthread_mutex_t		active_mx;
	pthread_mutex_t		print_mx;
}	t_args;

typedef struct s_fork
{
	int					fork_st;
	pthread_mutex_t		fork_mt;
}	t_fork;

typedef struct s_philo_info
{
	int				id;
	int				eats;
	struct timeval	last_eat;
	pthread_mutex_t	leat_mx;
	pthread_t		philo_thread;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_args			*args;
}	t_philo_info;

typedef struct s_system_info
{
	t_args			args;
	t_philo_info	*philos;
	t_fork			*forks;
}	t_system_info;

enum e_status_codes
{
	AVAIL,
	UNAVAIL,
	LIVE,
	DEAD,
	FULL
};

//philo_main_utils.c
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

//	philo_tycoon.c
int		run_philo_tycoon(t_system_info *_sys);

//philo_gotchi.c
void	*philo_gotchi(void *raw);

//philo_gotchi_utils.c
void	ft_usleep(int ms);
int		philo_timewatch(struct timeval last);
void	philo_printf(t_philo_info *philo, char *str);
int		philo_dying(t_philo_info *philo);

//philo_eating.c
int		philo_eating(t_philo_info *philo);

//philo_error_utils.c
int		str_is_digit(char *str);
int		philo_main_exit(void);
void	philo_timestamp(pthread_mutex_t *mx, struct timeval *time);

#endif
