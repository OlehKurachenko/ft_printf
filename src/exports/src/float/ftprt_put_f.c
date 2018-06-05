/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:09:41 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:09:42 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static const long long		g_f_type_deft_precision = 6;
static const long double	g_f_type_base = 10l;

static size_t				count_length(t_printff *const fl, long double val)
{
	size_t	res;
	size_t	i_res;

	if (val != val || val == g_flt_inf)
		return (0);
	res = 0;
	if (fl->prec == -1)
		fl->prec = g_f_type_deft_precision;
	if (fl->flags[6] || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->prec || fl->flags[0])
		++res;
	val /= g_f_type_base;
	i_res = 1;
	if (val == val && val != g_flt_inf)
		while (val >= 1)
		{
			val /= g_f_type_base;
			++i_res;
		}
	res += (fl->flags[4]) ? i_res + (i_res - 1) / 3 : i_res;
	return (res + fl->prec);
}

void						ftprt_put_f_byvalue(t_printff *const fl,
	const long double val)
{
	const size_t			len = count_length(fl, val);

	if (ftprt_handle_nans(fl, val))
		return ;
	if (fl->flags[1])
		ftprt_put_sign(fl);
	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '), fl->width - len);
	if (!fl->flags[1])
		ftprt_put_sign(fl);
	ftprt_put_float_base(val + 0.5l * ft_ldpow(1l / g_f_type_base,
		(size_t)fl->prec), g_f_type_base, fl);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += ft_max_size_t(fl->width, len);
}

void						ftprt_put_f(t_printff *const fl, va_list *const arg)
{
	ftprt_put_f_byvalue(fl, ftprt_set_fsign(fl, ftprt_va_get_fvalue(fl, arg)));
}
