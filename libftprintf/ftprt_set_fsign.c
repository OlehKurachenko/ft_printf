#include "ft_printf.h"

long double			ftprt_set_fsign(t_printff *const fl, long double val)
{
	fl->flags[6] = (unsigned char)(val < 0);
	if (val < 0)
		val = -val;
	return (val);
}

