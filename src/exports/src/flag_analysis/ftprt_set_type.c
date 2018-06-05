/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_set_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:02:56 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:02:57 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

const char		*ftprt_set_type(t_printff *const fl, const char *pos)
{
	const size_t	temp = (size_t)ft_strchr(g_types, *pos);

	if (temp && temp != (size_t)g_types)
		fl->type = (char)((temp - (size_t)g_types) / sizeof(char));
	else
	{
		if (*pos)
			ftprt_put_c_byval(fl, *pos);
		fl->type = CNV_TNUMB;
	}
	if (*pos)
		++pos;
	return (pos);
}
