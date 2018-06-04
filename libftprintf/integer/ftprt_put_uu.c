/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_uu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:31:44 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:31:45 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ftprt_put_uu(t_printff *const fl, va_list *const arg)
{
	fl->len_flag = 1;
	fl->type = 9;
	ftprt_put_u(fl, arg);
}
