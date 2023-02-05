/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:03:15 by jinam             #+#    #+#             */
/*   Updated: 2023/02/03 14:47:33 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	_str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i ++;
	}
	return (1);
}

int	philo_main_exit(void)
{
	write(2, "Usage: ./philo number_of_philosophers time_to_die", 49);
	write(2, " time_to_eat time_to_sleep", 26);
	write(2, " [number_of_times_each_philosopher_must_eat]\n", 46);
	return (1);
}
