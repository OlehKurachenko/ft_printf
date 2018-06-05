/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:10:06 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:10:07 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static const long double	g_type_base = 10l;

static size_t				count_ef_precision(t_printff *const fl,
	long double n_form)
{
	size_t				top_len;
	size_t				i;

	top_len = 0;
	i = 0;
	n_form = (n_form - (uintmax_t)n_form) * g_type_base;
	while ((long long)i++ < fl->prec)
	{
		if ((uintmax_t)n_form)
			top_len = i;
		n_form = (n_form - (uintmax_t)n_form) * g_type_base;
	}
	return (top_len);
}

static void					call_e(t_printff *const fl, const long double val)
{
	long double			n_form;

	ftprt_fgetexpon(fl, val, &n_form);
	if ((uintmax_t)n_form)
		--fl->prec;
	if (!fl->flags[0])
		fl->prec = (long long int)count_ef_precision(fl, n_form);
	fl->type = (char)((fl->type == 27) ? 15 : 16);
	ftprt_put_e_byvalue(fl, val);
}

static void					call_f(t_printff *const fl, const long double val)
{
	long double		tval;
	long double		downpow;

	tval = val + 0.5l * ft_ldpow(1l / g_type_base,
		(size_t)fl->prec);
	downpow = 1l;
	while ((tval / downpow) >= g_type_base)
		downpow *= g_type_base;
	if ((uintmax_t)tval)
		--fl->prec;
	while (tval >= g_type_base)
	{
		tval -= ((uintmax_t)(tval / downpow)) * downpow;
		if (fl->prec)
			--fl->prec;
		downpow /= g_type_base;
	}
	if (!fl->flags[0])
		fl->prec = (long long int)count_ef_precision(fl, tval);
	fl->type = (char)((fl->type == 27) ? 17 : 18);
	ftprt_put_f_byvalue(fl, val);
}

void						ftprt_put_g(t_printff *const fl, va_list *const arg)
{
	const long double	val = ftprt_set_fsign(fl, ftprt_va_get_fvalue(fl, arg));
	int					expon;

	if (ftprt_handle_nans(fl, val))
		return ;
	if (fl->prec == 0)
		fl->prec = 1;
	expon = ftprt_fgetexpon(fl, val, NULL);
	if (expon < -4 || expon >= fl->prec)
		call_e(fl, val);
	else
		call_f(fl, val);
}
