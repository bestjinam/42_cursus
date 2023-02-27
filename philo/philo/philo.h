/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:03:03 by jinam             #+#    #+#             */
/*   Updated: 2023/02/27 16:10:50 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int	argc;
	int	num;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	eat_cnt;
}	t_args;

typedef struct s_watchdog
{
	struct timeval	start;
	int				active;
	int				full;
	pthread_mutex_t	full_mt;
	pthread_mutex_t	active_mt;
	pthread_mutex_t	ready_mt;
}	t_watchdog;

typedef struct s_speaker
{
	int				print;
	pthread_mutex_t	print_mt;
}	t_speaker;

typedef struct s_fork
{
	int				fork;
	pthread_mutex_t	fork_mt;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				eats;
	int				last_eat;
	pthread_mutex_t	eats_mt;
	pthread_mutex_t	last_mt;
	pthread_t		philo;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_args			*args;
	t_watchdog		*watchdog;
	t_speaker		*speaker;
}	t_philo;

typedef struct s_room
{
	t_args		args;
	t_watchdog	watchdog;
	t_speaker	speaker;
	t_philo		*victims;
	t_fork		*forks;
}	t_room;

enum e_status
{
	SUCCESS,
	FAIL,
	INVALID_ARGS,
	INVALID,
	MALLOC_FAIL,
	AVAIL,
	UNAVAIL,
	ALIVE,
	DEAD,
	COMPLETE,
	INCOMPLETE
};

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr(int fd, char *str);
int		str_is_digit(char *str);
int		philo_err_exit(int err);
void	ft_usleep(struct timeval start, int ms);

int		checking_vital(t_watchdog *watchdog);
void	speaker_printf(t_philo *vct, char *str);
int		philo_watch(struct timeval start);

int		philo_dying(t_philo *victim);

int		checking_eat_time(t_philo *victim);
void	updating_eat_time(t_philo *victim);
int		preparing_forks(t_philo *victim);
void	releasing_forks(t_philo *victim);

void	*philo_tycoon(void *raw);
int		run_philo_game(t_room *room);
#endif
