#include "ft_printf.h"

void        ftprt_put_dd(t_printff *fl, va_list *arg,
                         int *nprt, t_putchar f_putchar)
{
    fl->len_flag = 1;
    fl->type = 4;
    ftprt_put_d(fl, arg, nprt, f_putchar);
}