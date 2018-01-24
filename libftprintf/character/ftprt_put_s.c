#include "../ft_printf.h"

void        ftprt_put_s(t_printff *fl, va_list *arg, int *nptr, t_putchar f_putchar)
{
	const char      *s;
	size_t          len;
    size_t          i;

	if (fl->len_flag == 1)
	{
		fl->type = 2;
		ftprt_put_ss(fl, arg, nptr, f_putchar);
		return ;
	}
	s = va_arg(*arg, const char *);
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