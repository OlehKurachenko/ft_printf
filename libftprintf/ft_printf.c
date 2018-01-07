#include "ft_printf.h"

const size_t        g_types_n = 27;

const t_type_proc   g_type_map[] =
		{
			&ftprt_put_dblpercent
		};

int 		        ft_printf(const char *format, ...)
{
	va_list                     vl;
	int                         res;

	va_start(vl, format);
	// TODO:	check is a format string manually ordered, if yes - call
	//			ft_lv_orderprintf
	//ft_lv_orderprintf();
	// TODO correct error exit & call

	res = ft_va_printf(format, &vl, &ft_putchar);
	va_end(vl);
	return (res);
}