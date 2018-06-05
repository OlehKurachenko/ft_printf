/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:07:46 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 11:07:47 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_va_printf(const char *format, va_list *arg, t_putchar f_putchar)
{
	t_printff	fl;
	const char	*pos = format;

	fl.ptchr = f_putchar;
	fl.count = 0;
	while (*pos)
	{
		pos = ftprt_set_flags(&fl, pos, arg);
		if (fl.type == -1)
		{
			f_putchar(*(pos++));
			++fl.count;
		}
		else if (fl.type != CNV_TNUMB)
			g_type_map[(size_t)fl.type](&fl, arg);
	}
	return (fl.count);
}
