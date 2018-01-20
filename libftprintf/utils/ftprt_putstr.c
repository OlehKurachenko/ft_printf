#include "../ft_printf.h"

void		ftprt_putstr(char const *s, t_putchar f_putchar)
{
	while (*s)
	{
		f_putchar(*s);
		++s;
	}
}
