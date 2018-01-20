#include "../ft_printf.h"

void		ftprt_put_sign(t_printff *const fl, t_putchar f_putchar)
{
	if (fl->flags[6])
		f_putchar('-');
	else
	if (fl->flags[3] || fl->flags[5])
		f_putchar((char)((fl->flags[3]) ? ' ' : '+'));
}