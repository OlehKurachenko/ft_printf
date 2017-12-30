/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ncp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 12:26:27 by okurache          #+#    #+#             */
/*   Updated: 2017/12/29 12:26:28 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew_ncp(void *content, size_t content_size)
{
	t_list		*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->c = content;
	node->c_size = content_size;
	node->next = NULL;
	return (node);
}
