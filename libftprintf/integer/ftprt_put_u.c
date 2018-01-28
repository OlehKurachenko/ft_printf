#include "../ft_printf.h"

void ftprt_put_u(t_printff *const fl, va_list *const arg)
{
    const uintmax_t		val = ftprt_va_get_uvalue(fl, arg);
    const size_t		len = ftprt_unumber_len(val,
		(unsigned char)((fl->precision != 0) ? 1 : 0), fl->flags[4]);
    size_t              used_len;

    if (fl->precision != -1)
        fl->flags[1] = 0;
    else
		if (fl->width > 0 && fl->flags[1])
		{
			fl->precision = (long long int)fl->width;
			fl->width = 0;
		}
    used_len = (fl->precision == -1 || (long long)len >
		fl->precision) ? len : (size_t)fl->precision;
    if (used_len < fl->width && (!fl->flags[2]))
        ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
                       fl->width - used_len);
    ftprt_put_unumber(val, len, fl);
    if (used_len < fl->width && fl->flags[2])
        ftprt_putnchar(fl, ' ', fl->width - used_len);
    fl->count += ft_max_size_t(fl->width, used_len);
}