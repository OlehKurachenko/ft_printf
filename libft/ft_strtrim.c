/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 14:46:48 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 14:46:51 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t			len;
	size_t			beg;
	size_t			end;
	char			*res;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	beg = 0;
	while ((s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t') && beg < len)
		++beg;
	end = len - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > beg)
		--end;
	++end;
	res = ft_strnew(end - beg);
	if (!res)
		return (NULL);
	ft_strncpy(res, s + beg, end - beg);
	return (res);
}
