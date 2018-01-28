#include "../ft_printf.h"

void		ftprt_putstr(t_printff *const fl, char const *s)
{
	while (*s)
	{
		fl->ptchr(*s);
		++s;
	}
}
