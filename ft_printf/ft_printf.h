/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:56:22 by jinam             #+#    #+#             */
/*   Updated: 2022/08/03 11:44:09 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef int	(*t_funcptr)(va_list);
int	ft_printf(const char *str, ...);
int	_printf_c(va_list ap);
int	_printf_s(va_list ap);
int	_convert_base(unsigned long nbr, char *base_from);
int	_printf_p(va_list ap);
int	_printf_d(va_list ap);
int	_printf_i(va_list ap);
int	_printf_u(va_list ap);
int	_printf_x(va_list ap);
int	_printf_xx(va_list ap);
int	_printf_per(va_list ap);
#endif
