#include "../ft_printf.h"

void ftprt_put_sign(t_printff *const fl)
{
	if (fl->flags[6])
		fl->ptchr('-');
	else
		if (fl->flags[3] || fl->flags[5])
			fl->ptchr((char)((fl->flags[3]) ? ' ' : '+'));
}