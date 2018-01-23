#include "ft_printf.h"

long double		ftprt_va_get_fvalue(t_printff *fl, va_list *arg)
{
	if (fl->len_flag == 6)
		return (va_arg(*arg, long double));
	return (va_arg(*arg, double));
}