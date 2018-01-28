#include "../ft_printf.h"

static void			put_uc(t_printff *const fl, unsigned char u)
{
	unsigned char	downpow;

	downpow = 1 << 7;
	while (downpow)
	{
		fl->ptchr((char)('0' + u / downpow));
		u %= downpow;
		downpow >>= 1;
	}
}

void				ftprt_put_bb(t_printff *const fl, va_list *const arg)
{
	const unsigned char	*addr = va_arg(*arg, unsigned char *);
	size_t				i;
	const size_t		prec = (size_t)((fl->precision < 0)
		? (-fl->precision) : fl->precision);
	const size_t		len = 8 * prec + ((fl->flags[4] && prec) ? prec - 1 : 0);

	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - len);
	i = 0;
	while (i < prec)
	{
		put_uc(fl, addr[i]);
		++i;
		if (fl->flags[4] && i != prec)
			fl->ptchr('.');
	}
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += ft_max_size_t(len, fl->width);
}