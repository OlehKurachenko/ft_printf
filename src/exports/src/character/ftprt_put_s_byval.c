/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_s_byval.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:32:08 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 15:32:09 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ftprt_put_s_byval(t_printff *const fl, const char *const s)
{
	size_t			len;
	size_t			i;

	len = (fl->prec == -1) ? ft_strlen(s)
			: ft_min_size_t(ft_strlen(s), (size_t)fl->prec);
	if (fl->width > len && !(fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '), fl->width - len);
	i = 0;
	while (i < len)
	{
		fl->ptchr(s[i]);
		++i;
	}
	if (fl->width > len && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += (fl->width > len) ? fl->width : len;
}
