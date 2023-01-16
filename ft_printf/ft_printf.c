#include <stdarg.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len += ft_putchar('-');
	if (n / 10 != 0)
	{
		if (n > 0)
			len += ft_putnbr(n / 10);
		else
			len += ft_putnbr(-(n / 10));
	}
	len += ft_putchar((n > 0 ? n % 10 : -(n % 10)) + '0');
	return (len);
}

int ft_putnbr_hex(unsigned int n)
{
	const char *base = "0123456789abcdef";
	int len;

	len = 0;
	if (n > 15)
	{
		len += ft_putnbr_hex(n / 16);
		len += ft_putnbr_hex(n % 16);
	}
	else 
		len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_printf(char *str, ...)
{
	va_list ap;
	int 	i;
	int		tmp;
	int		res;

	i = 0;
	res = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			tmp = ft_putchar(str[i]);
		else
		{
			i ++;
			if (str[i] == 's')
				tmp = ft_putstr(va_arg(ap, char *));
			else if (str[i] == 'd')
				tmp = ft_putnbr(va_arg(ap, int));
			else if (str[i] == 'x')
				tmp = ft_putnbr_hex(va_arg(ap, unsigned int));
		}
		if (tmp == -1)
			return (-1);
		else
			res += tmp;
		i++;
	}
	va_end(ap);
	return (res);
}


int main(void)
{
	ft_printf("%x %d\n", 0xa, -10);
}
