/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:10:11 by jinam             #+#    #+#             */
/*   Updated: 2022/12/24 17:15:26 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	return ;
}

void	ft_exit(char *msg, int err_num)
{
	ft_error_msg(msg);
	exit(err_num);
}
