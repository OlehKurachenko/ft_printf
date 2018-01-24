#include "../ft_printf.h"

void        ftprt_put_s(t_printff *fl, va_list *arg, int *nptr,
	t_putchar f_putchar)
{
	const char      *s;

	if (fl->len_flag == 1)
	{
		fl->type = 2;
		ftprt_put_ss(fl, arg, nptr, f_putchar);
		return ;
	}
	s = va_arg(*arg, const char *);
	if (!s)
		s = ftprt_null_str;
    ftprt_put_s_byval(fl, s, nptr, f_putchar);
}