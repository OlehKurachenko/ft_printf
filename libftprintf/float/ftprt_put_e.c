#include "../ft_printf.h"

static const long long		e_type_deft_precision = 6;
static const long double	e_type_base = 10l;

static size_t				count_length(t_printff *const fl, const int expon)
{
	size_t	res;

	res = 3 + ft_max_size_t(2,
							ftprt_number_len(expon, 1, 0));
	if (fl->precision == -1)
		fl->precision = e_type_deft_precision;
	if (fl->flags[6] || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->precision || fl->flags[0])
		++res;
	return (res + fl->precision);
}

void						ftprt_put_e(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar)
{
	const long double	val = ftprt_va_get_fvalue(fl, arg);
	long double			n_form;
	const int			expon = ftprt_fgetexpon(fl, val, e_type_base, &n_form);
	const size_t 		len = count_length(fl, expon);

	if (ftprt_handle_nans(fl, val, nptr, f_putchar))
		return ;
	if (fl->flags[1])
		ftprt_put_sign(fl, f_putchar);
	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar((char)((fl->flags[1]) ? '0' : ' '),
					   fl->width - len, f_putchar);
	if (!fl->flags[1])
		ftprt_put_sign(fl, f_putchar);
	ftprt_put_float_base(n_form, e_type_base, fl, f_putchar);
	f_putchar((char)((fl->type == 15) ? 'e' : 'E'));
	f_putchar((char)((expon >= 0) ? '+' : '-'));
	if (((expon >= 0) ? expon : -expon) < 10)
		f_putchar('0');
	ftprt_put_unumber_smpl((uintmax_t)((expon >= 0)
			? expon : -expon), f_putchar);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	*nptr += ft_max_size_t(len, fl->width);
}