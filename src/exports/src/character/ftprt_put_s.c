/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:31:40 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 15:31:41 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ftprt_put_s(t_printff *const fl, va_list *const arg)
{
	const char	*s;

	if (fl->len_flag == 1)
	{
		fl->type = 2;
		ftprt_put_ss(fl, arg);
		return ;
	}
	s = va_arg(*arg, const char *);
	if (!s)
		s = g_ftprt_null_str;
	ftprt_put_s_byval(fl, s);
}
