/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_dd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:30:31 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:30:32 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ftprt_put_dd(t_printff *const fl, va_list *const arg)
{
	fl->len_flag = 1;
	fl->type = 4;
	ftprt_put_d(fl, arg);
}
