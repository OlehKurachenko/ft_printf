#include "../ft_printf.h"

void	ftprt_put_s_byval(t_printff *const fl, const char *s, int *const nptr,
						   t_putchar f_putchar)
{
	size_t          len;
	size_t          i;

	len = (fl->precision == -1) ? ft_strlen(s)
			: ft_min_size_t(ft_strlen(s), (size_t)fl->precision);
	if (fl->width > len && !(fl->flags[2]))
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	i = 0;
	while (i < len)
	{
		f_putchar(s[i]);
		++i;
	}
	if (fl->width > len && (fl->flags[2]))
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	*nptr += (fl->width > len) ? fl->width : len;
}