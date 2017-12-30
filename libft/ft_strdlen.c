/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:28:59 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 15:29:03 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strdlen(const char *s, char c)
{
	size_t	result;

	result = 0;
	while (s[result] && s[result] != c)
		result++;
	return (result);
}
