/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:53:34 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 16:53:36 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (content == NULL)
	{
		node->c = NULL;
		node->c_size = 0;
	}
	else
	{
		node->c = malloc(content_size);
		if (!(node->c))
		{
			free(node);
			return (NULL);
		}
		ft_memcpy(node->c, content, content_size);
		node->c_size = content_size;
	}
	node->next = NULL;
	return (node);
}
