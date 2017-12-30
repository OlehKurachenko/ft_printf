/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 14:15:09 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 14:15:11 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			len;
	size_t			i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = f((unsigned int)i, s[i]);
	return (res);
}
