/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_c_byval.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:32:18 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 15:32:20 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ftprt_put_c_byval(t_printff *const fl, const char val)
{
	if (fl->width && !(fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '), fl->width - 1);
	fl->ptchr(val);
	if (fl->width && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - 1);
	fl->count += (fl->width) ? fl->width : 1;
}
