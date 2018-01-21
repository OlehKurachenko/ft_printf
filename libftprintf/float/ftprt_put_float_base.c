#include "../ft_printf.h"

static void		put_afterpoint_part(long double val, const long double base,
	t_printff *const fl, t_putchar f_putchar)
{
	const unsigned char	is_capital = (unsigned char)(fl->len_flag == 22);
	size_t				prec;

	if (fl->precision || fl->flags[0])
		f_putchar('.');
	if (!fl->precision)
		return ;
	prec = (size_t)fl->precision;
	val = (val - (uintmax_t)(val)) * base;
	while (prec > 0)
	{
		f_putchar(ftprt_getupdecimal((unsigned char)(val), is_capital));
		val = (val - (uintmax_t)(val)) * base;
		--prec;
	}
}

static void		put_prepoint_part(long double *const val, const long double base,
	t_printff *const fl, t_putchar f_putchar)
{
	const unsigned char	is_capital = (unsigned char)(fl->len_flag == 22);
	long double			downstep;

	downstep = 1l;
	while (*val / downstep >= base)
		downstep *= base;
	fl->flags[7] = 1;
	while (*val >= 1l || fl->flags[7])
	{
		f_putchar(ftprt_getupdecimal((unsigned char)(*val / downstep),
									  is_capital));
		*val -= (uintmax_t)(*val/downstep) * downstep;
		downstep /= base;
		fl->flags[7] = 0;
	}
}

static void		put_prepoint_part_apo(long double *const val, const long double base,
									 t_printff *const fl, t_putchar f_putchar)
{
	const unsigned char	is_capital = (unsigned char)(fl->len_flag == 22);
	long double			downstep;
	size_t				len_i;

	downstep = 1l;
	len_i = 0;
	while (*val / downstep >= base)
	{
		downstep *= base;
		++len_i;
	}
	fl->flags[7] = 1;
	while (*val >= 1l || fl->flags[7])
	{
		f_putchar(ftprt_getupdecimal((unsigned char)(*val / downstep),
									 is_capital));
		if (len_i % 3 == 0 && len_i)
			f_putchar(',');
		--len_i;
		*val -= (uintmax_t)(*val/downstep) * downstep;
		downstep /= base;
		fl->flags[7] = 0;
	}
}

/*
**	Here, flag[6] will be used to show that number is < 0
*/

void			ftprt_put_float_base(long double val, const long double base,
	t_printff *const fl, t_putchar f_putchar)
{
	if (fl->flags[4])
		put_prepoint_part_apo(&val, base, fl, f_putchar);
	else
		put_prepoint_part(&val, base, fl, f_putchar);
	put_afterpoint_part(val, base, fl, f_putchar);
}