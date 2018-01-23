#include "ft_printf.h"

static void				put_va_value(t_printff *const fl, va_list *const arg,
	t_putchar f_putchar, int *const res)
{
	va_list			va_tmp;
	short unsigned	i;

	va_copy(va_tmp, *arg);
	i = 0;
	while (i <fl->arg)
	{
		va_arg(va_tmp, unsigned);
		++i;
	}
	g_type_map[fl->type](fl, &va_tmp, res, f_putchar);
}

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
		pos = ftprt_set_flags_ordered(&fl, prev_pos = pos, arg);
		if (fl.type == -1)
		{
			f_putchar(*(pos++));
			++res;
		}
		else
			if (fl.type != CONV_TYPE_NUMB && fl.arg != 0)
				put_va_value(&fl, arg, f_putchar, &res);
			else
			{
				// TODO printf incorrect flag
			}
		if (fl.type != -1 && !fl.arg)
			return (res);
	}
	return (res);
}