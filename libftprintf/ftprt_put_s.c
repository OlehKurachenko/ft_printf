#include "ft_printf.h"

void        ftprt_put_s(t_printff *fl, va_list *arg, int *nptr, t_putchar f_putchar)
{
    const char      *s = va_arg(*arg, const char *);
    const size_t    len = (fl->precision == -1) ? ft_strlen(s)
                                                : ft_min_size_t(ft_strlen(s), (size_t)fl->precision);

    // TODO revrite above, analyse length of LV
    if (fl->len_flag == 1)
    {
        // TODO manage
    }
    if (fl->width > len && !(fl->flags[2]))
        ftprt_putnchar(' ', fl->width - len, f_putchar);
    // TODO string output
    if (fl->width > len && (fl->flags[2]))
        ftprt_putnchar(' ', fl->width - len, f_putchar);
}