/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:27:27 by jinam             #+#    #+#             */
/*   Updated: 2022/07/25 09:07:01 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
typedef struct s_node
{
	int				fd;
	char			buff[BUFFER_SIZE];
	size_t			offset;
	size_t			buff_len;
	struct s_node	*next;
}					t_node;
#endif /* ifndef GET_NEXT_LINE_H
# ifndef
 */
