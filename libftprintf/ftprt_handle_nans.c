#include "ft_printf.h"

static void					put_nan(t_printff *fl, unsigned char isNan, t_putchar f_putchar)
{
	if (isNan)
	{
		// TODO revrite this shit
		f_putchar((char)((fl->type % 2 == 1) ? 'n' : 'N'));
		f_putchar((char)((fl->type % 2 == 1) ? 'a' : 'A'));
		f_putchar((char)((fl->type % 2 == 1) ? 'n' : 'N'));
	}
	else
	{
		f_putchar((char)((fl->type % 2 == 1) ? 'i' : 'I'));
		f_putchar((char)((fl->type % 2 == 1) ? 'n' : 'N'));
		f_putchar((char)((fl->type % 2 == 1) ? 'f' : 'F'));
	}
}

unsigned char		ftprt_handle_nans(t_printff *fl,
	const long double val, int *nptr, t_putchar f_putchar)
{
	size_t	len;

	if (val == val && val != flt_inf)
		return (0);
	len = (val == flt_inf && ((fl->flags[6]) || (!fl->flags[6]
		&& (fl->flags[3] || fl->flags[5])))) ? 4 : 3;
	if (len < fl->width && !fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	if (val == flt_inf && fl->flags[6])
		f_putchar('-');
	else
		if ((fl->flags[3] || fl->flags[5]) && val == flt_inf && !fl->flags[6])
			f_putchar((char)((fl->flags[3]) ? ' ' : '+'));
	put_nan(fl, (unsigned char)(val != val), f_putchar);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	*nptr += ft_max_size_t(len, fl->width);
	return (1);
}