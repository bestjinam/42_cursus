/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:56:22 by jinam             #+#    #+#             */
/*   Updated: 2022/08/06 22:05:31 by jinam            ###   ########.fr       */
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

int			_init_str(t_format *format, int size);
void		_bit_mod_flags(t_format *format);
typedef int	(*t_funcptr)(t_format *, va_list);
int			ft_printf(const char *str, ...);
int			_parsing_flags(const char *str, t_format *format);
int			_printf_c(t_format *format, va_list ap);
int			_printf_s(t_format *format, va_list ap);
int			_convert_base(unsigned long nbr, char *base_from);
int			_printf_p(t_format *format, va_list ap);
int			_printf_d(t_format *format, va_list ap);

int			_printf_d_width(int width, char c);
int			_print_sign(t_format *format, long nbr);

int			_printf_d_zero_precision_zero_process(t_format *format);
int			_printf_d_minus_process(t_format *f, long n, int l, char *b);
int			_printf_d_zero_process(t_format *f, long n, int l, char *b);
int			_printf_d_plain_process(t_format *f, long n, int l, char *b);

int			_printf_base16_process(t_format *f, unsigned long n, char *b);
int			_printf_p_width(int width, char c);
int			_p_minus_process(t_format *f, unsigned long n, int l, char *b);
int			_p_zero_process(t_format *f, unsigned long n, int l, char *b);
int			_p_plain_process(t_format *f, unsigned long n, int l, char *b);
int			_p_zero_precision_zero_process(t_format *format);
int			_p_prenumber_print(t_format *format, unsigned long nbr);

int			_printf_u(t_format *format, va_list ap);
int			_printf_x(t_format *format, va_list ap);
int			_printf_xx(t_format *format, va_list ap);
int			_printf_per(t_format *format, va_list ap);
#endif
