#include "ft_printf.h"

void		ftprt_put_c(t_printff *fl, va_list *arg, int *nprt,
						t_putchar f_putchar)
{
	char      c;

	if (fl->len_flag == 1)
	{
		fl->type = 13;
		ftprt_put_cc(fl, arg, nprt, f_putchar);
		return ;
	}
	c = (char)va_arg(*arg, int);
	if (fl->width && !(fl->flags[2]))
		ftprt_putnchar(' ', fl->width - 1, f_putchar);
	f_putchar(c);
	if (fl->width && (fl->flags[2]))
		ftprt_putnchar(' ', fl->width - 1, f_putchar);
	*nprt += (fl->width) ? fl->width : 1;
}
