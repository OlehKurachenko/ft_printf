/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_dblpercent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:32:35 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 15:32:36 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ftprt_put_dblpercent(t_printff *const fl, va_list *const arg)
{
	if (fl && arg)
		fl->ptchr('%');
	++fl->count;
}
