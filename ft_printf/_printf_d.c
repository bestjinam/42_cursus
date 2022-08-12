/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:42:21 by jinam             #+#    #+#             */
/*   Updated: 2022/08/12 16:38:56 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	_nbr_d_zero_precision_zero_process(t_format *f, t_temp_str *t_str)
{
	const int	res1 = ((f->flags & PLUS) == PLUS || \
						(f->flags & SPACE) == SPACE);

	if ((f->flags & MINUS) == MINUS)
	{
		if ((f->flags & PLUS) == PLUS)
			ft_c_append(t_str, '+');
		else if ((f->flags & SPACE) == SPACE)
			ft_c_append(t_str, ' ');
		_printf_width(t_str, f->width - res1, ' ');
	}
	else
	{
		_printf_width(t_str, f->width - res1, ' ');
		if ((f->flags & PLUS) == PLUS)
			ft_c_append(t_str, '+');
		else if ((f->flags & SPACE) == SPACE)
			ft_c_append(t_str, ' ');
	}
	return (0);
}

int	_nbr_d_minus_process(t_format *f, t_temp_str *t_str, long n, char *b)
{
	const char	*conv_n = ft_itoa_base(n * ((n > 0) - (n < 0)), b);
	int			len;

	if (!conv_n)
		return (-1);
	len = ft_strlen(conv_n);
	if (n < 0)
		ft_c_append(t_str, '-');
	else if ((f->flags & PLUS) == PLUS)
		ft_c_append(t_str, '+');
	else if ((f->flags & SPACE) == SPACE)
		ft_c_append(t_str, ' ');
	if ((f->flags & PRECISION) == PRECISION)
		_printf_width(t_str, f->precision - len, '0');
	ft_s_append(t_str, (char *) conv_n);
	_printf_width(t_str, f->width - t_str->len, ' ');
	free((void *)conv_n);
	return (0);
}

int	_nbr_d_zero_process(t_format *f, t_temp_str *t_str, long n, char *b)
{
	const char	*conv_n = ft_itoa_base(n * ((n > 0) - (n < 0)), b);
	int			len;

	if (!conv_n)
		return (-1);
	len = ft_strlen(conv_n);
	if (n < 0)
		ft_c_append(t_str, '-');
	else if ((f->flags & PLUS) == PLUS)
		ft_c_append(t_str, '+');
	else if ((f->flags & SPACE) == SPACE)
		ft_c_append(t_str, ' ');
	_printf_width(t_str, f->width - (t_str->len + len), '0');
	ft_s_append(t_str, (char *) conv_n);
	free((void *)conv_n);
	return (0);
}

int	_nbr_d_noflag_process(t_format *f, t_temp_str *t_str, long n, char *b)
{
	const char	*conv_n = ft_itoa_base(n * ((n > 0) - (n < 0)), b);
	int			len;
	int			res1;

	if (!conv_n)
		return (-1);
	len = ft_strlen(conv_n);
	res1 = ((n < 0) || (f->flags & PLUS) == PLUS || \
			(f->flags & SPACE) == SPACE);
	if (f->precision > len)
		_printf_width(t_str, f->width - (f->precision + res1), ' ');
	else
		_printf_width(t_str, f->width - (len + res1), ' ');
	if (n < 0)
		ft_c_append(t_str, '-');
	else if ((f->flags & PLUS) == PLUS)
		ft_c_append(t_str, '+');
	else if ((f->flags & SPACE) == SPACE)
		ft_c_append(t_str, ' ');
	if ((f->flags & PRECISION) == PRECISION)
		_printf_width(t_str, f->precision - len, '0');
	ft_s_append(t_str, (char *) conv_n);
	_printf_width(t_str, f->width - (t_str->len), ' ');
	free((void *)conv_n);
	return (0);
}

int	_printf_d(t_temp_str *t_str, t_format *f, va_list *ap)
{
	long			nbr;
	const char		*base = "0123456789";
	int				res;

	nbr = (long) va_arg(*ap, int);
	if ((f->flags & PRECISION) == PRECISION && f->precision == 0 && nbr == 0)
		res = _nbr_d_zero_precision_zero_process(f, t_str);
	else if ((f->flags & MINUS) == MINUS)
		res = _nbr_d_minus_process(f, t_str, nbr, (char *) base);
	else if ((f->flags & ZERO) == ZERO)
		res = _nbr_d_zero_process(f, t_str, nbr, (char *) base);
	else
		res = _nbr_d_noflag_process(f, t_str, nbr, (char *) base);
	if (res == -1)
		return (-1);
	return (ft_temp_print(t_str, 1));
}
