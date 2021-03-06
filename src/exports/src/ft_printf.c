/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:07:15 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 11:07:16 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "output_modules/ftprt_buffered_putchar.h"

const t_type_proc	g_type_map[CNV_TNUMB] =
{
	&ftprt_put_dblpercent,
	&ftprt_put_s,
	&ftprt_put_ss,
	&ftprt_put_p,
	&ftprt_put_d,
	&ftprt_put_dd,
	&ftprt_put_d,
	&ftprt_put_o,
	&ftprt_put_oo,
	&ftprt_put_u,
	&ftprt_put_uu,
	&ftprt_put_x,
	&ftprt_put_x,
	&ftprt_put_c,
	&ftprt_put_cc,
	&ftprt_put_e,
	&ftprt_put_e,
	&ftprt_put_f,
	&ftprt_put_f,
	&ftprt_put_n,
	&ftprt_put_k,
	&ftprt_put_kk,
	&ftprt_put_b,
	&ftprt_put_bb,
	&ftprt_put_r,
	&ftprt_put_r,
	&ftprt_put_g,
	&ftprt_put_g,
	&ftprt_put_a,
	&ftprt_put_a
};

int					ft_printf(const char *format, ...)
{
	va_list	vl;
	int		res;

	va_start(vl, format);
	if (ordered_chech(format))
		res = ft_va_printf_ordered(format, &vl, &ftprt_buffered_putchar);
	else
		res = ft_va_printf(format, &vl, &ftprt_buffered_putchar);
	va_end(vl);
	ftprt_buffer_flush();
	return (res);
}
