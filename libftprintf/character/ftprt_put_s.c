#include "../ft_printf.h"

void        ftprt_put_s(t_printff *const fl, va_list *const arg)
{
	const char      *s;

	if (fl->len_flag == 1)
	{
		fl->type = 2;
		ftprt_put_ss(fl, arg);
		return ;
	}
	s = va_arg(*arg, const char *);
	if (!s)
		s = ftprt_null_str;
    ftprt_put_s_byval(fl, s);
}