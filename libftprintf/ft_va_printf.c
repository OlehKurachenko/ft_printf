#include "ft_printf.h"

int     ft_va_printf(const char *format, va_list *arg)
{
	t_printff		fl;
	const char      *pos = format;
	int             res;

	res = 0;
	while (*pos)
	{
		pos = ftprt_set_flags(&fl, pos);
		if (fl.type == -1)
		{
			ft_putchar(*(pos++));
			++res;
		}
		else
			if (fl.type != 28)
				g_type_map[fl.type](&fl, arg, &res);
	}
	return (res);
}
