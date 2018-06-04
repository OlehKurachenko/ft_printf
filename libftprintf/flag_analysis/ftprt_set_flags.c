/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_set_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:02:03 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:02:04 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

const char	*ftprt_set_flags(t_printff *fl, const char *pos, va_list *arg)
{
	if (*pos != '%')
	{
		fl->type = -1;
		return (pos);
	}
	++pos;
	pos = ftprt_set_fflags(fl, pos);
	pos = ftprt_set_fwidth(fl, pos, arg);
	pos = ftprt_set_fprecision(fl, pos, arg);
	pos = ftprt_set_flen_flag(fl, pos);
	pos = ftprt_set_type(fl, pos);
	return (pos);
}
