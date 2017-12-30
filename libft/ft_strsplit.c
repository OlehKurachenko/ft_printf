/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:24:59 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 15:25:01 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	ft_strdup_sp(char **ptr, char const *src, char c)
{
	size_t		i;

	*ptr = (char *)malloc(sizeof(char) * (ft_strdlen(src, c) + 1));
	if (!(*ptr))
		return (0);
	i = 0;
	while (src[i] != 0 && src[i] != c)
	{
		(*ptr)[i] = src[i];
		i++;
	}
	(*ptr)[i] = 0;
	return (i);
}

static void		ft_strsplit_clrarr(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i++ < len)
		free(arr[i]);
	free(arr);
}

static size_t	ft_strsplit_nwords(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	nwords;

	i = 0;
	j = 1;
	nwords = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && j)
			nwords++;
		j = (str[i++] == c);
	}
	return (nwords);
}

char			**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	nwords;
	char	**ptr;

	if (!str)
		return (NULL);
	nwords = ft_strsplit_nwords(str, c);
	ptr = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		while (*str == c)
			str++;
		str += ft_strdup_sp(&ptr[i], str, c);
		if (!(ptr[i]))
		{
			ft_strsplit_clrarr(ptr, i);
			return (NULL);
		}
		++i;
	}
	ptr[i] = (char *)0;
	return (ptr);
}
