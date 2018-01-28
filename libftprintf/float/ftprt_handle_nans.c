#include "../ft_printf.h"

unsigned char ftprt_handle_nans(t_printff *const fl, const long double val)
{
	size_t	len;

	if (val == val && val != flt_inf)
		return (0);
	len = (val == flt_inf && ((fl->flags[6]) || (!fl->flags[6]
		&& (fl->flags[3] || fl->flags[5])))) ? 4 : 3;
	if (len < fl->width && !fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	if (val == flt_inf && fl->flags[6])
		fl->ptchr('-');
	else
		if ((fl->flags[3] || fl->flags[5]) && val == flt_inf && !fl->flags[6])
			fl->ptchr((char)((fl->flags[3]) ? ' ' : '+'));
	if (fl->type % 2 == 1)
		ftprt_putstr(fl, (val != val) ? "nan" : "inf");
	else
		ftprt_putstr(fl, (val != val) ? "NAN" : "INF");
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += ft_max_size_t(len, fl->width);
	return (1);
}