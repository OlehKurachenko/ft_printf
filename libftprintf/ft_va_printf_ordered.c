#include "ft_printf.h"

int     				ft_va_printf_ordered(const char *format,
	va_list *arg, t_putchar f_putchar)
{
	t_printff		fl;
	const char      *pos = format;
	const char      *prev_pos;
	int             res;

	res = 0;
	while (*pos)
	{
		prev_pos = pos;
		pos = ftprt_set_flags(&fl, pos, arg);
		if (fl.type == -1)
		{
			f_putchar(*(pos++));
			++res;
		}
		else
			// TODO write and add here carousel
			if (fl.type != CONV_TYPE_NUMB && fl.arg != 0)
				g_type_map[fl.type](&fl, arg, &res, f_putchar);
			else
			{
				// TODO printf incorrect flag
			}
		if (fl.arg == 0)
			return (res);
	}
	return (res);
}