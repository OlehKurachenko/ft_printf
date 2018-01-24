#include "../ft_printf.h"

void    ftprt_put_p(t_printff *fl, va_list *arg,
					int *nprt, t_putchar f_putchar)
{
	fl->flags[0] = 1;
	fl->len_flag = 0;
	fl->type = 11;
	fl->flags[6] = 1;
	ftprt_put_x(fl, arg, nprt, f_putchar);
}