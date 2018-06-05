/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_set_flags_ordered.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:02:11 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:02:12 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

const char	*set_index(const char *pos, t_printff *const fl)
{
	unsigned short	res;

	res = 0;
	while (ft_isdigit(*pos))
	{
		res = (unsigned short)(res * 10 + *pos - '0');
		++pos;
	}
	fl->arg = (unsigned short)((*pos == '$') ? res : 0);
	return (pos + 1);
}

const char	*ftprt_set_flags_ordered(t_printff *fl,
	const char *pos, va_list *arg)
{
	if (*pos != '%')
	{
		fl->type = -1;
		return (pos);
	}
	++pos;
	pos = set_index(pos, fl);
	pos = ftprt_set_fflags(fl, pos);
	pos = ftprt_set_fwidth(fl, pos, arg);
	pos = ftprt_set_fprecision(fl, pos, arg);
	pos = ftprt_set_flen_flag(fl, pos);
	pos = ftprt_set_type(fl, pos);
	return (pos);
}
