/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:10:13 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:10:14 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ftprt_put_sign(t_printff *const fl)
{
	if (fl->flags[6])
		fl->ptchr('-');
	else if (fl->flags[3] || fl->flags[5])
		fl->ptchr((char)((fl->flags[3]) ? ' ' : '+'));
}
