/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:18:07 by jinam             #+#    #+#             */
/*   Updated: 2022/11/21 14:01:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

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
