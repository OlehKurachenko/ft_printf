/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:09:27 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:09:28 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static size_t				count_unloss_length(long double n_form)
{
	size_t		res;
	long double	prev;

	res = 0;
	prev = n_form;
	n_form = (n_form - (intmax_t)n_form) * 16l;
	while (prev > n_form || n_form > prev)
	{
		++res;
		prev = n_form;
		n_form = (n_form - (intmax_t)n_form) * 16l;
	}
	return ((res) ? res - 1 : res);
}

static size_t				count_length(t_printff *const fl,
	const long double n_form, const int expon)
{
	size_t	res;

	res = 5 + ftprt_nlen((intmax_t)expon, 1, 0);
	if (fl->prec == -1 && !(n_form != n_form || n_form == g_flt_inf))
		fl->prec = (long long int)count_unloss_length(n_form);
	if (fl->flags[6] || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->prec || fl->flags[0])
		++res;
	return (res + fl->prec);
}

static void					put_sign_block(t_printff *const fl)
{
	ftprt_put_sign(fl);
	fl->ptchr('0');
	fl->ptchr((char)((fl->type == 29) ? 'x' : 'X'));
}

void						ftprt_put_a(t_printff *const fl, va_list *const arg)
{
	const long double	v = ftprt_set_fsign(fl, ftprt_va_get_fvalue(fl, arg));
	long double			n_form;
	const int			expon = ftprt_agetexpon(fl, v, &n_form);
	const size_t		len = count_length(fl, n_form, expon);

	if (ftprt_handle_nans(fl, v))
		return ;
	if (fl->flags[1])
		put_sign_block(fl);
	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '), fl->width - len);
	if (!fl->flags[1])
		put_sign_block(fl);
	ftprt_put_float_base(n_form, 16l, fl);
	fl->ptchr((char)((fl->type == 29) ? 'p' : 'P'));
	fl->ptchr((char)((expon >= 0) ? '+' : '-'));
	ftprt_put_unumber_smpl(fl, (uintmax_t)((expon >= 0)
			? expon : -expon));
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += ft_max_size_t(len, fl->width);
}
