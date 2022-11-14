/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:21:11 by jinam             #+#    #+#             */
/*   Updated: 2022/11/14 19:17:18 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pipe.h"

void	ft_perror(char *error)
{
	perror(error);
	exit(1);
}

void	ft_exit(char *str, int sig)
{
	ft_putendl_fd(str, 2);
	exit(sig);
}
