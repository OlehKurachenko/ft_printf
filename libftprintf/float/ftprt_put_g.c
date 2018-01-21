#include "../ft_printf.h"

static const long double	g_type_base = 10l;

static void					call_e(t_printff *const fl, const long double val,
	int *nprt, t_putchar f_putchar)
{
	long double			n_form;
	int 				expon = ftprt_fgetexpon(fl, val, g_type_base, &n_form);
	size_t				top_len;


	fl->precision -= 2;
	// TODO write
}

static void					call_f(t_printff *const fl, const long double val,
	int *nprt, t_putchar f_putchar)
{
	// TODO write
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