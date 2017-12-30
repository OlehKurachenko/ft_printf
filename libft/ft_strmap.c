/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 14:07:02 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 14:07:03 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
		res[i] = f(s[i]);
	return (res);
}
