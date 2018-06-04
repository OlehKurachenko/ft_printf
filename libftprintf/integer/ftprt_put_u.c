/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:31:31 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:31:32 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ftprt_put_u(t_printff *const fl, va_list *const arg)
{
	const uintmax_t	val = ftprt_va_get_uvalue(fl, arg);
	const size_t	len = ftprt_ulen(val, (fl->prec != 0), fl->flags[4]);
	size_t			used_len;

	if (fl->prec != -1)
		fl->flags[1] = 0;
	else if (fl->width > 0 && fl->flags[1])
	{
		fl->prec = (long long int)fl->width;
		fl->width = 0;
	}
	used_len = (fl->prec == -1 || (long long)len >
		fl->prec) ? len : (size_t)fl->prec;
	if (used_len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
		fl->width - used_len);
	ftprt_put_unumber(val, len, fl);
	if (used_len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - used_len);
	fl->count += ft_max_size_t(fl->width, used_len);
}
