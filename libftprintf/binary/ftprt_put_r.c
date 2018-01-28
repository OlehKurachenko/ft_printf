/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:29:31 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 14:29:32 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				ftprt_put_r(t_printff *const fl, va_list *const arg)
{
	const unsigned char	*addr = va_arg(*arg, unsigned char *);
	size_t				i;
	const size_t		prec = (size_t)((fl->precision < 0)
			? (-fl->precision) : fl->precision);
	const size_t		len = 2 * prec + ((fl->flags[4] && prec) ? prec - 1 : 0);

	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - len);
	i = 0;
	while (i < prec)
	{
		fl->ptchr(ftprt_getupdecimal((unsigned char)(addr[i] / 16),
			(unsigned char)(fl->type == 25)));
		fl->ptchr(ftprt_getupdecimal((unsigned char)(addr[i] % 16),
			(unsigned char)(fl->type == 25)));
		++i;
		if (fl->flags[4] && i != prec)
			fl->ptchr('.');
	}
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += ft_max_size_t(len, fl->width);
}
