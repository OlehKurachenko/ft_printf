/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:31:17 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:31:20 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ftprt_put_p(t_printff *const fl, va_list *const arg)
{
	fl->flags[0] = 1;
	fl->len_flag = 0;
	fl->type = 11;
	fl->flags[6] = 1;
	ftprt_put_x(fl, arg);
}
