#include "../ft_printf.h"

void        ftprt_put_u(t_printff *fl, va_list *arg,
                        int *nprt, t_putchar f_putchar)
{
    const uintmax_t     val = ftprt_va_get_uvalue(fl, arg);
    const size_t        len = ftprt_unumber_len(val,
         (fl->precision != 0) ? 1 : 0, fl->flags[4]);
    size_t              used_len;

    if (fl->precision != -1)
        fl->flags[1] = 0;
    else
    if (fl->width > 0 && fl->flags[1])
    {
        fl->precision = fl->width;
        fl->width = 0;
    }
    used_len = (fl->precision == -1 || len >
		(long long unsigned)fl->precision) ? len : fl->precision;
    if (used_len < fl->width && (!fl->flags[2]))
        ftprt_putnchar((fl->flags[1]) ? '0' : ' ',
                       fl->width - used_len, f_putchar);
    ftprt_put_unumber(val, len, fl, f_putchar);
    if (used_len < fl->width && fl->flags[2])
        ftprt_putnchar((fl->flags[1]) ? '0' : ' ',
                       fl->width - used_len, f_putchar);
    *nprt += ft_max_size_t(fl->width, used_len);
}