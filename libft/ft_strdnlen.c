/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:38:00 by okurache          #+#    #+#             */
/*   Updated: 2017/12/29 17:38:01 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strdnlen(const char *s, char c, size_t n)
{
	size_t	result;

	result = 0;
	while (s[result] && s[result] != c && n-- > 0)
		result++;
	return (result);
}
