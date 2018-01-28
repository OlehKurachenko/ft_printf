#include "../ft_printf.h"

void ftprt_put_dd(t_printff *const fl, va_list *const arg)
{
    fl->len_flag = 1;
    fl->type = 4;
    ftprt_put_d(fl, arg);
}