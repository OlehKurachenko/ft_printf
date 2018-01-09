#include "ft_printf.h"

const t_type_proc   g_type_map[CONV_TYPE_NUMB] =
		{
			&ftprt_put_dblpercent,
			&ftprt_put_s,
			&ftprt_put_ss,
            NULL,   // TODO replace with 'p'
            &ftprt_put_d,
            &ftprt_put_dd,
            &ftprt_put_d,
            NULL,   // TODO replace with 'o'
            NULL,	// TODO replace with 'O'
			&ftprt_put_u,
			&ftprt_put_uu
		};

int                 ft_printf(const char *format, ...)
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