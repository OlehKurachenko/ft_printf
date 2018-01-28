#include "ft_printf.h"

int     ft_va_printf(const char *format, va_list *arg, t_putchar f_putchar)
{
	t_printff		fl;
	const char      *pos = format;

	fl.ptchr = f_putchar;
	fl.count = 0;
	while (*pos)
	{
		pos = ftprt_set_flags(&fl, pos, arg);
		if (fl.type == -1)
		{
			f_putchar(*(pos++));
			++fl.count;
		}
		else
			if (fl.type != CONV_TYPE_NUMB)
				g_type_map[(size_t)fl.type](&fl, arg);
	}
	return (fl.count);
}
