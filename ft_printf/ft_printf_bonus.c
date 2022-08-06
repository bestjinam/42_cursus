/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:16:06 by jinam             #+#    #+#             */
/*   Updated: 2022/08/06 18:32:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static void	_make_flags(t_format *format, char c)
{
	const char	*flags = "+- #0.";
	int			flags_idx;

	flags_idx = ft_strchr(flags, c) - flags;
	if (flags_idx >= 0)
		format->flags |= (1 << (ft_strchr(flags, c) - flags));
	else
		return ;
}

int	_parsing_flags(const char *str, t_format *format)
{
	static char	*options = "cspdiuxX%";
	int			i;

	i = 0;
	while (ft_strchr(options, str[i]) == 0)
	{
		if (!ft_isdigit(str[i]))
			_make_flags(format, str[i ++]);
		else if (str[i] == '0' && (i == 0 || (i != 0 && str[i - 1] != '.')))
			_make_flags(format, str[i ++]);
		else
		{
			if (i != 0 && str[i - 1] == '.')
				format->precision = ft_atoi(&str[i]);
			else
				format->width = ft_atoi(&str[i]);
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	if (str[i] == 0)
		return (-1);
	else
		format->specifier = str[i++];
	return (i);
}

void	_bit_mod_flags(t_format *format)
{
	if ((format->flags & 040) == 040 || (format->flags & 02) == 02)
		format->flags &= ~020;
	if ((format -> flags & 01) == 01)
		format->flags &= ~04;
}

int	_init_str(t_format *format, int size)
{
	int	str_size;

	if (format->width < size)
		str_size = size;
	else
		str_size = format->width;
	format->str = malloc(sizeof(char) * (str_size + 1));
	format->str[str_size] = 0;
	return (str_size);
}
