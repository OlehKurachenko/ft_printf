#include "../ft_printf.h"

void ftprt_put_uu(t_printff *const fl, va_list *const arg)
{
    fl->len_flag = 1;
    fl->type = 9;
	ftprt_put_u(fl, arg);
}