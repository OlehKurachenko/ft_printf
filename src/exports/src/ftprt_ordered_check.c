/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_ordered_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:08:06 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 11:08:07 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned char	ordered_chech(const char *fstr)
{
	while (*fstr)
	{
		if (*fstr == '%')
		{
			++fstr;
			if (ft_isdigit(*fstr))
			{
				while (ft_isdigit(*fstr))
					++fstr;
				if (*fstr == '$')
					return (1);
			}
		}
		++fstr;
	}
	return (0);
}
