#include "../ft_printf.h"

static const size_t		ftprt_base = 8;

static void             ftprt_put_onumber_apo(uintmax_t val, size_t len,
    t_printff *const fl)
{
    uintmax_t       pw;
    size_t          delim_c;

    if (fl->precision != -1 && ((long long unsigned)fl->precision > len))
        ftprt_putnchar(fl, '0', fl->precision - len);
    if (val || fl->precision != 0)
    {
        pw = 1;
		delim_c = 0;
        while (val / pw >= ftprt_base && ++delim_c)
            pw *= ftprt_base;
        while (pw)
        {
			fl->ptchr((char)('0' + val / pw));
            if (delim_c && (delim_c-- % 3 == 0))
                fl->ptchr(',');
            val %= pw;
            pw /= ftprt_base;
        }
    }
}

void ftprt_put_onumber(uintmax_t val, size_t len, t_printff *const fl)
{
    uintmax_t       pw;

    if (fl->flags[4])
        return (ftprt_put_onumber_apo(val, len, fl));
    if (fl->precision != -1 && ((long long unsigned)fl->precision > len))
        ftprt_putnchar(fl, '0', fl->precision - len);
    if (val || fl->precision != 0)
    {
        pw = 1;
        while (val / pw >= ftprt_base)
            pw *= ftprt_base;
        while (pw)
        {
            fl->ptchr((char)('0' + val / pw));
            val %= pw;
            pw /= ftprt_base;
        }
    }
}