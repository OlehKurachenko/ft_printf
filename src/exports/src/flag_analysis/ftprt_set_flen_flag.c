/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_set_flen_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:02:25 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:02:26 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

const char	*ftprt_set_flen_flag(t_printff *fl, const char *pos)
{
	if (*pos == 'l' && *(pos + 1) == 'l')
		return (pos + ((fl->len_flag = 0) + 2));
	if (*pos == 'h' && *(pos + 1) == 'h')
		return (pos + (fl->len_flag = 2));
	if (*pos == 'l')
		return (pos + (fl->len_flag = 1));
	if (*pos == 'h')
		return (pos + ((fl->len_flag = 3) - 2));
	if (*pos == 'j')
		return (pos + ((fl->len_flag = 4) - 3));
	if (*pos == 'z')
		return (pos + ((fl->len_flag = 5) - 4));
	if (*pos == 'L')
		return (pos + ((fl->len_flag = 6) - 5));
	fl->len_flag = -1;
	return (pos);
}
