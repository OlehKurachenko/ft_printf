#include "../ft_printf.h"

void				ftprt_put_r(t_printff *fl, va_list *arg,
								 int *nprt, t_putchar f_putchar)
{
	const unsigned char	*addr = va_arg(*arg, unsigned char *);
	size_t				i;
	const size_t		prec = (size_t)((fl->precision < 0)
			? (-fl->precision) : fl->precision);
	const size_t		len = 2 * prec + ((fl->flags[4] && prec) ? prec - 1 : 0);

	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	i = 0;
	while (i < prec)
	{
		f_putchar(ftprt_getupdecimal((unsigned char)(addr[i] / 16),
			(unsigned char)(fl->type == 25)));
		f_putchar(ftprt_getupdecimal((unsigned char)(addr[i] % 16),
			(unsigned char)(fl->type == 25)));
		++i;
		if (fl->flags[4] && i != prec)
			f_putchar('.');
	}
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	*nprt += ft_max_size_t(len, fl->width);
}