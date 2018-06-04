/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:07:33 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 11:07:34 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "output_modules/ftprt_buffered_putchar_str.h"

int					ft_sprintf(const char **const str, const char *format, ...)
{
	va_list	vl;
	int		res;

	ftprt_buffer_init_str();
	va_start(vl, format);
	if (ordered_chech(format))
		res = ft_va_printf_ordered(format, &vl, &ftprt_buffered_putchar_str);
	else
		res = ft_va_printf(format, &vl, &ftprt_buffered_putchar_str);
	va_end(vl);
	*str = ftprt_buffer_get_str();
	return (res);
}
