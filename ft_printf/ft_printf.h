/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:56:22 by jinam             #+#    #+#             */
/*   Updated: 2022/08/05 20:46:26 by jinam            ###   ########.fr       */
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
	char			*str;
	int				space_size;
}	t_format;

int _init_str(t_format *format, int size);
typedef int	(*t_funcptr)(t_format *, va_list);
int	ft_printf(const char *str, ...);
int	_parsing_flags(const char *str, t_format *format);
int	_printf_c(t_format *format, va_list ap);
int	_printf_s(t_format *format, va_list ap);
int	_convert_base(unsigned long nbr, char *base_from);
int	_printf_p(t_format *format, va_list ap);
int	_printf_d(t_format *format, va_list ap);
int	_printf_i(t_format *format, va_list ap);
int	_printf_u(t_format *format, va_list ap);
int	_printf_x(t_format *format, va_list ap);
int	_printf_xx(t_format *format, va_list ap);
int	_printf_per(t_format *format, va_list ap);
#endif
