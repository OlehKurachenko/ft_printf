#include "../ft_printf.h"

static void	precision_case(t_printff *fl, const size_t len, const uintmax_t val)
{
	fl->flags[5] = (unsigned char)(fl->precision == -1);
	if (fl->flags[0] && val && fl->precision <= (long long)len)
		fl->precision = len + 1;
	if (fl->flags[0] && (!val) && fl->precision == 0)
		fl->precision = 1;
	if (fl->precision != -1)
	{
		if (!fl->flags[5])
			fl->flags[1] = 0;
	}
	else
	if (fl->width > 0 && fl->flags[1])
		fl->precision = fl->width;
}

/*
**	Here, fl.flag[5] is special flag shows was there a presicion in call
*/

void		ftprt_put_o(t_printff *fl, va_list *arg, int *nptr,
		t_putchar f_putchar)
{
	const uintmax_t     val = ftprt_va_get_uvalue(fl, arg);
	const size_t        len = ftprt_unumber_baselen(val,
		(fl->precision != 0) ? 1 : fl->flags[0], fl->flags[4], 8);
	size_t              used_len;


	precision_case(fl, len, val);
	used_len = (fl->precision == -1 || len > fl->precision)
			   ? len : fl->precision;
	if (used_len < fl->width && (!fl->flags[2]))
		ftprt_putnchar((fl->flags[1]) ? '0' : ' ',
					   fl->width - used_len, f_putchar);
	ftprt_put_onumber(val, len, fl, f_putchar);
	if (used_len < fl->width && fl->flags[2])
		ftprt_putnchar((fl->flags[1]) ? '0' : ' ',
			fl->width - used_len, f_putchar);
	*nptr += ft_max_size_t(fl->width, used_len);
}