#include "ft_printf.h"

void				ftprt_put_n(t_printff *fl, va_list *arg,
								 int *nprt, t_putchar f_putchar)
{
	if (!f_putchar)
		return ;
	if (fl->len_flag == -1 || fl->len_flag == 6)
		*(va_arg(*arg, int *)) = *nprt;
	if (fl->len_flag == 0)
		*(va_arg(*arg, long long *)) = *nprt;
	if (fl->len_flag == 1)
		*(va_arg(*arg, long *)) = *nprt;
	if (fl->len_flag == 2)
		*(va_arg(*arg, signed char *)) = (signed char)*nprt;
	if (fl->len_flag == 3)
		*(va_arg(*arg, short *)) = (short)*nprt;
	if (fl->len_flag == 4)
		*(va_arg(*arg, intmax_t *)) = *nprt;
	if (fl->len_flag == 5)
		*(va_arg(*arg, size_t *)) = (size_t)*nprt;
}