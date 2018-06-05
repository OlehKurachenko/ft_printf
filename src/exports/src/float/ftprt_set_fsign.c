/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_set_fsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:10:30 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:10:31 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

long double			ftprt_set_fsign(t_printff *const fl, long double val)
{
	fl->flags[6] = (unsigned char)(val < 0);
	if (val < 0)
		val = -val;
	return (val);
}
