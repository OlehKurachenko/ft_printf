#include "../ft_printf.h"

static void             ftprt_put_xnumber_apo(uintmax_t val, size_t len,
	t_printff *fl, t_putchar f_putchar)
{
	uintmax_t       pw;
	size_t          delim_c;

	if (fl->flags[delim_c = 0])
	{
		f_putchar('0');
		f_putchar((char)((fl->type == 11) ? 'x' : 'X'));
	}
	if (fl->precision != -1 && (fl->precision > (long long)len))
		ftprt_putnchar('0', fl->precision - len, f_putchar);
	if (val || fl->precision != 0)
	{
		pw = 1;
		while (val / pw >= 16 && ++delim_c)
			pw *= 16;
		while (pw)
		{
			f_putchar(ftprt_getupdecimal((unsigned char)(val / pw),
				(unsigned char)(fl->type != 11)));
			if (delim_c && (delim_c-- % 3 == 0))
				f_putchar(',');
			val %= pw;
			pw /= 16;
		}
	}
}

void                    ftprt_put_xnumber(uintmax_t val, size_t len,
	t_printff *fl, t_putchar f_putchar)
{
	uintmax_t       pw;

	if (fl->flags[4])
		return (ftprt_put_xnumber_apo(val, len, fl, f_putchar));
	if (fl->flags[0])
	{
		f_putchar('0');
		f_putchar((char)((fl->type == 11) ? 'x' : 'X'));
	}
	if (fl->precision != -1 && (fl->precision > (long long)len))
		ftprt_putnchar('0',
					   fl->precision - len, f_putchar);
	if (val || fl->precision != 0)
	{
		pw = 1;
		while (val / pw >= 16)
			pw *= 16;
		while (pw)
		{
			f_putchar(ftprt_getupdecimal((unsigned char)(val / pw),
				(unsigned char)(fl->type != 11)));
			val %= pw;
			pw /= 16;
		}
	}
}