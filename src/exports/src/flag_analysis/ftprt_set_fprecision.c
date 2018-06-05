/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_set_fprecision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:02:34 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:02:35 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

/*
** fl->len_flag used as temporary variable
*/

const char	*ftprt_set_fprecision(t_printff *fl, const char *pos,
	va_list *arg)
{
	if (*pos == '.')
	{
		fl->prec = 0;
		++pos;
		if (*pos == '*')
		{
			fl->len_flag = va_arg(*arg, int);
			if (fl->len_flag >= 0)
				fl->prec = fl->len_flag;
			else
				fl->prec = -1;
			return (pos + 1);
		}
		while (ft_isdigit(*pos))
		{
			fl->prec *= 10;
			fl->prec += *pos - '0';
			++pos;
		}
	}
	else
		fl->prec = -1;
	return (pos);
}
