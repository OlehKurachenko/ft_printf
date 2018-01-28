#include "../ft_printf.h"

void		ftprt_put_c_byval(t_printff *const fl, const char val)
{
	if (fl->width && !(fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - 1);
	fl->ptchr(val);
	if (fl->width && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - 1);
	fl->count += (fl->width) ? fl->width : 1;
}