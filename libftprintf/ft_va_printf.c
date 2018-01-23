#include "ft_printf.h"

int     ft_va_printf(const char *format, va_list *arg, t_putchar f_putchar)
{
	t_printff		fl;
	const char      *pos = format;
	int             res;

	res = 0;
	while (*pos)
	{
		pos = ftprt_set_flags(&fl, pos, arg);
		if (fl.type == -1)
		{
			f_putchar(*(pos++));
			++res;
		}
		else
			if (fl.type != CONV_TYPE_NUMB)
				g_type_map[fl.type](&fl, arg, &res, f_putchar);
	}
	return (res);
}
