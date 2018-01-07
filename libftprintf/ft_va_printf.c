#include "ft_printf.h"

int     ft_va_printf(const char *format, va_list *arg, t_putchar f_putchar)
{
	t_printff		fl;
	const char      *pos = format;
	const char      *prev_pos;
	int             res;

	res = 0;
	while (*pos)
	{
		prev_pos = pos;
		pos = ftprt_set_flags(&fl, pos);
		if (fl.type == -1)
		{
			f_putchar(*(pos++));
			++res;
		}
		else
			if (fl.type != 28)
				g_type_map[fl.type](&fl, arg, &res, f_putchar);
			else
			{
				// TODO printf incorrect flag
			}
	}
	return (res);
}
