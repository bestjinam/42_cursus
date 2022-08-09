#include "ft_printf.h"

int	print_init(t_info *info, va_list *ap)
{
	static int	(*g_print[8])(t_info *, va_list *) = {p_c, p_s, p_p,
		p_id, p_id, p_u, p_x, p_xu};
	int			conv;
	int			len;

	conv = info->conv;
	if (0 <= conv && conv <= 7)
		len = g_print[conv](info, ap);
	else
		len = p_per(info);
	return (len);
}√
