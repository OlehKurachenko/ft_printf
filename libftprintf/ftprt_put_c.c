#include "ft_printf.h"

void		ftprt_put_c(t_printff *fl, va_list *arg, int *nprt,
						t_putchar f_putchar)
{
	char      c;

	if (fl->len_flag == 1)
	{
		// TODO configure call to ftprt_put_cc
//		fl->type = 2;
//		ftprt_put_ss(fl, arg, nptr, f_putchar);
//		return ;
	}
	c = va_arg(*arg, char);
	if (fl->width && !(fl->flags[2]))
		ftprt_putnchar(' ', fl->width - 1, f_putchar);
	f_putchar(c);
	if (fl->width && (fl->flags[2]))
		ftprt_putnchar(' ', fl->width - 1, f_putchar);
	*nprt += (fl->width) ? fl->width : 1;
}
