/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_va_get_fvalue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:10:38 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:10:39 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long double		ftprt_va_get_fvalue(t_printff *fl, va_list *arg)
{
	if (fl->len_flag == 6)
		return (va_arg(*arg, long double));
	return (va_arg(*arg, double));
}
