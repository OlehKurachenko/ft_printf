#include "ft_printf.h"

int     ft_va_printf_ordered(const char *format, va_list *arg, t_putchar f_putchar)
{
	// TODO refactor
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
		if (fl.type != CONV_TYPE_NUMB)
			g_type_map[fl.type](&fl, arg, &res, f_putchar);
		else
		{
			// TODO printf incorrect flag
		}
	}
	return (res);
}