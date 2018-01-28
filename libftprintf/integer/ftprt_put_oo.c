#include "../ft_printf.h"

void ftprt_put_oo(t_printff *const fl, va_list *const arg)
{
	fl->len_flag = 1;
	fl->type = 7;
	ftprt_put_o(fl, arg);
}