/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_handle_nans.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:09:18 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:09:19 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned char	ftprt_handle_nans(t_printff *const fl, const long double val)
{
	size_t	len;

	if (val == val && val != g_flt_inf)
		return (0);
	len = (val == g_flt_inf && ((fl->flags[6]) || (!fl->flags[6]
		&& (fl->flags[3] || fl->flags[5])))) ? 4 : 3;
	if (len < fl->width && !fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	if (val == g_flt_inf && fl->flags[6])
		fl->ptchr('-');
	else if ((fl->flags[3] || fl->flags[5]) &&
		val == g_flt_inf && !fl->flags[6])
		fl->ptchr((char)((fl->flags[3]) ? ' ' : '+'));
	if (fl->type % 2 == 1)
		ftprt_putstr(fl, (val != val) ? "nan" : "inf");
	else
		ftprt_putstr(fl, (val != val) ? "NAN" : "INF");
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += ft_max_size_t(len, fl->width);
	return (1);
}
