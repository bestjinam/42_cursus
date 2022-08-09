/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:40:55 by jinam             #+#    #+#             */
/*   Updated: 2022/08/09 14:03:15 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			specifier;
	int				space_size;
}	t_format;

typedef enum e_flags
{
	PLUS = 1 << 0,
	MINUS = 1 << 1,
	SPACE = 1 << 2,
	SHARP = 1 << 3,
	ZERO = 1 << 4,
	PRECISION = 1 << 5
}	t_flags;

#endif
