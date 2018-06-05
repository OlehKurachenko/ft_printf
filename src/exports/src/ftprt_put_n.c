/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:08:15 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 11:08:16 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				ftprt_put_n(t_printff *const fl, va_list *const arg)
{
	if (fl->len_flag == -1 || fl->len_flag == 6)
		*(va_arg(*arg, int *)) = fl->count;
	if (fl->len_flag == 0)
		*(va_arg(*arg, long long *)) = fl->count;
	if (fl->len_flag == 1)
		*(va_arg(*arg, long *)) = fl->count;
	if (fl->len_flag == 2)
		*(va_arg(*arg, signed char *)) = (signed char)fl->count;
	if (fl->len_flag == 3)
		*(va_arg(*arg, short *)) = (short)fl->count;
	if (fl->len_flag == 4)
		*(va_arg(*arg, intmax_t *)) = fl->count;
	if (fl->len_flag == 5)
		*(va_arg(*arg, size_t *)) = (size_t)fl->count;
}
