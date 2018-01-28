#include "ft_printf.h"

static void				put_va_value(t_printff *const fl, va_list *const arg)
{
	va_list			va_tmp;
	short unsigned	i;

	va_copy(va_tmp, *arg);
	i = 1;
	while (i <fl->arg)
	{
		va_arg(va_tmp, long long unsigned);
		++i;
	}
	g_type_map[(size_t)fl->type](fl, &va_tmp);
}

int     				ft_va_printf_ordered(const char *const format,
	va_list *const arg, t_putchar f_putchar)
{
	t_printff		fl;
	const char      *pos = format;

	fl.ptchr = f_putchar;
	fl.count = 0;
	while (*pos)
	{
		pos = ftprt_set_flags_ordered(&fl, pos, arg);
		if (fl.type == -1)
		{
			f_putchar(*(pos++));
			++fl.count;
		}
		else
			if (fl.type != CONV_TYPE_NUMB && fl.arg != 0)
				put_va_value(&fl, arg);
		if (fl.type != -1 && !fl.arg)
			return (fl.count);
	}
	return (fl.count);
}