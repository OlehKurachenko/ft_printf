#include "../ft_printf.h"

/*
**  Flag fl->flags[3] is auto-set by 0, and than used as
**  width-to-precision delegation flag
*/

void ftprt_put_x(t_printff *const fl, va_list *const arg)
{
    const uintmax_t     val = ftprt_va_get_uvalue(fl, arg);
    const size_t        len = ftprt_unumber_baselen(val,
         (fl->precision != 0) ? 1 : 0, fl->flags[4], 16);
    size_t              used_len;

    fl->flags[0] = (unsigned char)((val || fl->flags[6]) ? fl->flags[0] : 0);
    if (fl->precision != -1)
        fl->flags[1] = 0;
    else
		if (fl->width > 0 && fl->flags[1])
		{
			fl->precision = fl->width - ((fl->flags[0]) ? 2 : 0);
			fl->width = 0;
		}
    used_len = (fl->precision == -1 ||
			(long long)len > fl->precision) ? len : (size_t)fl->precision;
    used_len += (fl->flags[0]) ? 2 : 0;
    if (used_len < fl->width && (!fl->flags[2]))
        ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
                       fl->width - used_len);
	ftprt_put_xnumber(val, len, fl);
    if (used_len < fl->width && fl->flags[2])
        ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
                       fl->width - used_len);
    fl->count += ft_max_size_t(fl->width, used_len);
}