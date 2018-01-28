#include "../ft_printf.h"

void		ftprt_put_c(t_printff *const fl, va_list *const arg)
{
	char      c;

	if (fl->len_flag == 1)
	{
		fl->type = 13;
		ftprt_put_cc(fl, arg);
		return ;
	}
	c = (char)va_arg(*arg, int);
	if (fl->width && !(fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '), fl->width - 1);
	fl->ptchr(c);
	if (fl->width && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - 1);
	fl->count += (fl->width) ? fl->width : 1;
}
