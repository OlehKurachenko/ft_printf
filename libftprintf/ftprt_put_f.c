#include "ft_printf.h"

static const long long		f_type_deft_precision = 6;
static const long double	f_type_base = 10l;

static size_t 				count_length(t_printff *const fl, long double val)
{
	size_t	res;
	size_t	i_res;

	if (val != val || val == flt_inf)
		return (0);
	res = 0;
	if (fl->precision == -1)
		fl->precision = f_type_deft_precision;
	if (fl->flags[6] || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->precision || fl->flags[0])
		++res;
	val /= f_type_base;
	i_res = 1;
	if (val == val && val != flt_inf)
		while (val >= 1)
		{
			val /= f_type_base;
			++i_res;
		}
	res += (fl->flags[4]) ? i_res + (i_res - 1) / 3 : i_res;
	return (res + fl->precision);
}

void						ftprt_put_f_byvalue(t_printff *const fl,
	const long double val, int *const nprt, t_putchar f_putchar)
{
	const size_t 		len = count_length(fl, val);

	if (ftprt_handle_nans(fl, val, nprt, f_putchar))
		return ;
	if (fl->flags[1])
		ftprt_put_sign(fl, f_putchar);
	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar((char)((fl->flags[1]) ? '0' : ' '),
					   fl->width - len, f_putchar);
	if (!fl->flags[1])
		ftprt_put_sign(fl, f_putchar);
	ftprt_put_float_base(val + 0.5l * ft_ldpow(1l / f_type_base,
		(size_t)fl->precision), f_type_base, fl, f_putchar);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	;
	*nprt += ft_max_size_t(fl->width, len);
}

void						ftprt_put_f(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar)
{
	ftprt_put_f_byvalue(fl, ftprt_set_fsign(fl, ftprt_va_get_fvalue(fl, arg)),
						nptr, f_putchar);
}