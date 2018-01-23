#include "ft_printf.h"

static const size_t infinite_loop_number = 100000;

static size_t				count_unloss_length(long double n_form)
{
	size_t		res;
	long double	prev;

	res = 0;
	prev = n_form;
	n_form = (n_form - (intmax_t)n_form) * 16l;
	while (prev > n_form || n_form > prev)
	{
		++res;
		prev = n_form;
		n_form = (n_form - (intmax_t)n_form) * 16l;
	}
	return ((res) ? res - 1 : res);
}

static size_t				count_length(t_printff *const fl,
	const long double n_form, const int expon)
{
	size_t	res;

	res = 5 + ftprt_number_len((intmax_t)expon, 1, 0);
	if (fl->precision == -1 && !(n_form != n_form || n_form == flt_inf))
		fl->precision = (long long int)count_unloss_length(n_form);
	if (fl->flags[6] || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->precision || fl->flags[0])
		++res;
	return (res + fl->precision);
}

static int 					agetexpon(t_printff *const fl,
										long double val, long double *const n_form)
{
	int		res;
	size_t	i;

	if (val != val || val == flt_inf)
		return (0);
	res = 0;
	while (val >= 16l)
	{
		val /= 2l;
		++res;
	}
	i = 0;
	while (val < 8l && ++i < infinite_loop_number)
	{
		val *= 2l;
		--res;
	}
	while ((val += 0.5l * ft_ldpow(1l / 16l, (size_t)fl->precision)) >= 16l)
	{
		val /= 2l;
		++res;
	}
	if (n_form)
		*n_form = val;
	return ((i == infinite_loop_number) ? 0 : res);
}

static void					put_sign_block(t_printff *const fl,
	t_putchar f_putchar)
{
	ftprt_put_sign(fl, f_putchar);
	f_putchar('0');
	f_putchar((char)((fl->type == 29) ? 'x' : 'X'));
}

void						ftprt_put_a(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar)
{
	const long double	v = ftprt_set_fsign(fl, ftprt_va_get_fvalue(fl, arg));
	long double			n_form;
	const int			expon = agetexpon(fl, v, &n_form);
	const size_t 		len = count_length(fl, n_form, expon);

	if (ftprt_handle_nans(fl, v, nptr, f_putchar))
		return ;
	if (fl->flags[1])
		put_sign_block(fl, f_putchar);
	if (len < fl->width && (!fl->flags[2])) ftprt_putnchar(
		(char)((fl->flags[1]) ? '0' : ' '), fl->width - len, f_putchar);
	if (!fl->flags[1])
		put_sign_block(fl, f_putchar);
	ftprt_put_float_base(n_form, 16l, fl, f_putchar);
	f_putchar((char)((fl->type == 29) ? 'p' : 'P'));
	f_putchar((char)((expon >= 0) ? '+' : '-'));
	ftprt_put_unumber_smpl((uintmax_t)((expon >= 0)
			? expon : -expon), f_putchar);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	*nptr += ft_max_size_t(len, fl->width);
}