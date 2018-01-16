#include "ft_printf.h"

static const long long		e_type_deft_precision = 6;
static const long double	e_type_base = 10l;

static size_t				count_length(t_printff *const fl,
	long double n_from_val, const int expon)
{
	size_t	res;

	res = 3 + ft_max_size_t(2,
							ftprt_number_len(expon, 1, 0));
	if (fl->precision == -1)
		fl->precision = e_type_deft_precision;
	if (n_from_val < 0 || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->precision || fl->flags[0])
		++res;
	return (res + fl->precision);
}

static void					put_nan(unsigned char isNan, t_putchar f_putchar)
{
	if (isNan)
	{
		f_putchar('n');
		f_putchar('a');
		f_putchar('n');
	}
	else
	{
		f_putchar('i');
		f_putchar('n');
		f_putchar('f');
	}
}

static unsigned char		handle_nan_vals(t_printff *fl,
	const long double val, int *nptr, t_putchar f_putchar)
{
	size_t	len;

	if (val == val && val != flt_neg_inf && val != flt_pos_inf)
		return (0);
	len = (val == flt_neg_inf || ((fl->flags[3] || fl->flags[5])
		&& val == flt_pos_inf)) ? 4 : 3;
	if (len < fl->width && !fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	if (val == flt_neg_inf)
		f_putchar('-');
	else
	if ((fl->flags[3] || fl->flags[5]) && val == flt_pos_inf)
		f_putchar((char)((fl->flags[3]) ? ' ' : '+'));
	put_nan((unsigned char) (val != val), f_putchar);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	*nptr += ft_max_size_t(len, fl->width);
	return (1);
}

void						ftprt_put_e(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar)
{
	const long double	val = ftprt_va_get_fvalue(fl, arg);
	long double			n_form;
	const int			expon = ftprt_fgetexpon(val, e_type_base, &n_form);
	const size_t 		len = count_length(fl, n_form, expon);

	if (handle_nan_vals(fl, val, nptr, f_putchar))
		return ;
	if (fl->flags[1] && (fl->flags[3] || fl->flags[5]))
		f_putchar((char)((fl->flags[3]) ? ' ' : '+'));
	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar((char)((fl->flags[1]) ? '0' : ' '),
					   fl->width - len, f_putchar);
	ftprt_put_float_base(n_form, e_type_base, fl, f_putchar);
	f_putchar((char)((fl->type == 15) ? 'e' : 'E'));
	f_putchar((char)((expon >= 0) ? '+' : '-'));
	if (((expon >= 0) ? expon : -expon) < 10)
		f_putchar('0');
	ftprt_put_unumber_smpl((uintmax_t)((expon >= 0)
			? expon : -expon), f_putchar);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	;
	*nptr += ft_max_size_t(len, fl->width);
}