/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:38:24 by jinam             #+#    #+#             */
/*   Updated: 2022/11/09 13:35:44 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include "../libft/get_next_line/get_next_line_bonus.h"
#include "../libft/ft_printf/ft_printf.h"
int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("test.txt",O_RDONLY);
	fd2 = open("test.txt",O_RDONLY);
	ft_printf("%s\n",get_next_line(fd1));
	ft_printf("%s\n",get_next_line(fd2));
}
