/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:29:16 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 14:29:18 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t		get_byte_len(const t_printff *const fl)
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

void				ftprt_put_b(t_printff *const fl, va_list *const arg)
{
	uintmax_t 		val;
	const size_t	byte_len = get_byte_len(fl);
	uintmax_t		downpow;

	val = ftprt_va_get_uvalue(fl, arg);
	if (8 * byte_len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - 8 * byte_len);
	downpow = (uintmax_t)1 << (8 * byte_len - 1);
	while (downpow) {
		fl->ptchr((char)('0' + val / downpow));
		val %= downpow;
		downpow >>= 1;
	}
	if (8 * byte_len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - 8 * byte_len);
	fl->count += ft_max_size_t(fl->width, 8 * byte_len);
}
