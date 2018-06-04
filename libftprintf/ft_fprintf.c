/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:07:07 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 11:07:08 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "output_modules/ftprt_buffered_putchar_fd.h"

int					ft_fprintf(const int fd, const char *format, ...)
{
	va_list	vl;
	int		res;

	ftprt_buffer_set_fd(fd);
	va_start(vl, format);
	if (ordered_chech(format))
		res = ft_va_printf_ordered(format, &vl, &ftprt_buffered_putchar_fd);
	else
		res = ft_va_printf(format, &vl, &ftprt_buffered_putchar_fd);
	va_end(vl);
	ftprt_buffer_flush_fd();
	return (res);
}
