/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_oo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:31:06 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:31:07 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ftprt_put_oo(t_printff *const fl, va_list *const arg)
{
	fl->len_flag = 1;
	fl->type = 7;
	ftprt_put_o(fl, arg);
}
