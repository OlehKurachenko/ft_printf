#include "../ft_printf.h"

static const long double	e_type_base = 10l;

static size_t				count_length(t_printff *const fl, const int expon)
{
	size_t	res;

	res = 3 + ft_max_size_t(2,
							ftprt_number_len(expon, 1, 0));
	if (fl->flags[6] || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->precision || fl->flags[0])
		++res;
	return (res + fl->precision);
}

void ftprt_put_e_byvalue(t_printff *const fl, const long double val)
{
	long double			n_form;
	const int			expon = ftprt_fgetexpon(fl, val, e_type_base, &n_form);
	const size_t 		len = count_length(fl, expon);

	if (ftprt_handle_nans(fl, val))
		return ;
	if (fl->flags[1])
		ftprt_put_sign(fl);
	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
					   fl->width - len);
	if (!fl->flags[1])
		ftprt_put_sign(fl);
	ftprt_put_float_base(n_form, e_type_base, fl);
	fl->ptchr((char)((fl->type == 15) ? 'e' : 'E'));
	fl->ptchr((char)((expon >= 0) ? '+' : '-'));
	if (((expon >= 0) ? expon : -expon) < 10)
		fl->ptchr('0');
	ftprt_put_unumber_smpl(fl, (uintmax_t)((expon >= 0)
			? expon : -expon));
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += ft_max_size_t(len, fl->width);
}

void ftprt_put_e(t_printff *const fl, va_list *const arg)
{
	ftprt_put_e_byvalue(fl, ftprt_set_fsign(fl, ftprt_va_get_fvalue(fl, arg)));
}