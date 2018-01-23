#include "ft_printf.h"

static size_t		get_byte_len(t_printff *fl)
{
	if (fl->len_flag == -1)
		return (sizeof(unsigned));
	if (fl->len_flag == 0)
		return (sizeof(unsigned long long));
	if (fl->len_flag == 1)
		return (sizeof(unsigned long));
	if (fl->len_flag == 2)
		return (sizeof(unsigned char));
	if (fl->len_flag == 3)
		return (sizeof(unsigned short));
	if (fl->len_flag == 4)
		return (sizeof(intmax_t));
	return (sizeof(ssize_t));
}

void				ftprt_put_b(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar)
{
	uintmax_t 		val;
	const size_t	byte_len = get_byte_len(fl);
	uintmax_t		downpow;

	val = ftprt_va_get_uvalue(fl, arg);
	if (8 * byte_len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(' ', fl->width - 8 * byte_len, f_putchar);
	downpow = (uintmax_t)1 << (8 * byte_len - 1);
	while (downpow) {
		f_putchar((char)('0' + val / downpow));
		val %= downpow;
		downpow >>= 1;
	}
	if (8 * byte_len < fl->width && fl->flags[2])
		ftprt_putnchar(' ', fl->width - 8 * byte_len, f_putchar);
	*nprt += ft_max_size_t(fl->width, 8 * byte_len);
}