#include "ft_printf.h"

void		ftprt_put_oo(t_printff *fl, va_list *arg, int *nprt,
						 t_putchar f_putchar)
{
	fl->len_flag = 1;
	fl->type = 7;
	ftprt_put_o(fl, arg, nprt, f_putchar);
}