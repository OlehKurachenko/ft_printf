#include "../ft_printf.h"

void        ftprt_put_uu(t_printff *fl, va_list *arg,
                         int *nprt, t_putchar f_putchar)
{
    fl->len_flag = 1;
    fl->type = 9;
    ftprt_put_u(fl, arg, nprt, f_putchar);
}