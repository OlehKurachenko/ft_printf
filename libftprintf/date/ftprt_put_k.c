#include "../ft_printf.h"

static void			put_time(const t_time_t *const time, t_putchar f_putchar)
{
	f_putchar('T');
	ftprt_putnchar('0', (size_t)(2
		- ftprt_unumber_len(time->hour, 1, 0)), f_putchar);
	ftprt_put_unumber_smpl(time->hour, f_putchar);
	f_putchar(':');
	ftprt_putnchar('0', (size_t)(2
		- ftprt_unumber_len(time->minute, 1, 0)), f_putchar);
	ftprt_put_unumber_smpl(time->minute, f_putchar);
	f_putchar(':');
	ftprt_putnchar('0', (size_t)(2
		- ftprt_unumber_len(time->second, 1, 0)), f_putchar);
	ftprt_put_unumber_smpl(time->second, f_putchar);
	f_putchar('Z');
}

void				ftprt_put_k(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar)
{
	const t_time_t	*const time = construct_t_time_t_uf(va_arg(*arg, time_t));
	const size_t	len = (fl->flags[0]) ? 10 : 20;

	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	ftprt_putnchar('0', (size_t)(4
		- ftprt_unumber_len(time->year, 1, 0)), f_putchar);
	ftprt_put_unumber_smpl(time->year, f_putchar);
	f_putchar('-');
	ftprt_putnchar('0', (size_t)(2
		- ftprt_unumber_len(time->month, 1, 0)), f_putchar);
	ftprt_put_unumber_smpl(time->month, f_putchar);
	f_putchar('-');
	ftprt_putnchar('0', (size_t)(2
		- ftprt_unumber_len(time->day, 1, 0)), f_putchar);
	ftprt_put_unumber_smpl(time->day, f_putchar);
	if (fl->flags[0])
		put_time(time, f_putchar);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	destruct_const_t_time_t(time);
	*nprt += ft_max_size_t(len, fl->width);
}