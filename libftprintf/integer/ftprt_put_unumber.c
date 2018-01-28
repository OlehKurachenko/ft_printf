#include "../ft_printf.h"

static void		ftprt_put_unumber_apo(uintmax_t val, size_t len, t_printff *const fl)
{
    uintmax_t   pw;
    size_t      delim_c;

    if (fl->precision != -1 && (fl->precision > (long long)len))
        ftprt_putnchar(fl, '0', fl->precision - len);
    if (val || fl->precision != 0)
    {
        pw = 1;
        delim_c = 0;
        while (val / pw > 9 && ++delim_c)
            pw *= 10;
        while (pw)
        {
            fl->ptchr((char)('0' + val / pw));
            if (delim_c && (delim_c-- % 3 == 0))
                fl->ptchr(',');
            val %= pw;
            pw /= 10;
        }
    }
}

void			ftprt_put_unumber(uintmax_t val, size_t len, t_printff *const fl)
{
	uintmax_t pw;

    if (fl->flags[4])
        return (ftprt_put_unumber_apo(val, len, fl));
	if (fl->precision != -1 && (fl->precision > (long long)len))
		ftprt_putnchar(fl, '0', fl->precision - len);
	if (val || fl->precision != 0)
	{
		pw = 1;
		while (val / pw > 9)
			pw *= 10;
		while (pw)
		{
			fl->ptchr((char)('0' + val / pw));
			val %= pw;
			pw /= 10;
		}
	}
}