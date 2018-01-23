#include "ft_printf.h"

static const long double	g_type_base = 10l;

static size_t				count_ef_precision(t_printff *const fl, long double n_form)
{
	size_t				top_len;
	size_t				i;

	top_len = 0;
	i = 0;
	n_form = (n_form - (uintmax_t)n_form) * g_type_base;
	while ((long long)i++ < fl->precision)
	{
		if ((uintmax_t) n_form)
			top_len = i;
		n_form = (n_form - (uintmax_t)n_form) * g_type_base;
	}
	return (top_len);
}

static void					call_e(t_printff *const fl, const long double val,
	int *nprt, t_putchar f_putchar)
{
	long double			n_form;

	ftprt_fgetexpon(fl, val, g_type_base, &n_form);
	if ((uintmax_t)n_form)
		--fl->precision;
	if (!fl->flags[0])
		fl->precision = (long long int)count_ef_precision(fl, n_form);
	fl->type = (char)((fl->type == 27) ? 15 : 16);
	ftprt_put_e_byvalue(fl, val, nprt, f_putchar);
}

static void					call_f(t_printff *const fl, const long double val,
	int *nprt, t_putchar f_putchar)
{
	long double		tval;
	long double		downpow;

	tval = val + 0.5l * ft_ldpow(1l / g_type_base,
		(size_t)fl->precision);
	downpow = 1l;
	while ((tval / downpow) >= g_type_base)
		downpow *= g_type_base;
	if ((uintmax_t)tval)
		--fl->precision;
	while (tval >= g_type_base)
	{
		tval -= ((uintmax_t)(tval / downpow)) * downpow;
		if (fl->precision)
			--fl->precision;
		downpow /= g_type_base;
	}
	if (!fl->flags[0])
		fl->precision = (long long int)count_ef_precision(fl, tval);
	fl->type = (char)((fl->type == 27) ? 17 : 18);
	ftprt_put_f_byvalue(fl, val, nprt, f_putchar);
}

void						ftprt_put_g(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar)
{
	const long double	val = ftprt_set_fsign(fl, ftprt_va_get_fvalue(fl, arg));
	int 				expon = ftprt_fgetexpon(fl, val, g_type_base, NULL);

	if (ftprt_handle_nans(fl, val, nptr, f_putchar))
		return ;
	if (fl->precision == -1)
		fl->precision = 6;
	if (fl->precision == 0)
		fl->precision = 1;
	if (expon < -4 || expon >= fl->precision)
		call_e(fl, val, nptr, f_putchar);
	else
		call_f(fl, val, nptr, f_putchar);
}