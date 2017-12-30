/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:27:14 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 17:27:16 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		**temp;
	t_list		*n_list;

	if (!f)
		return (NULL);
	n_list = NULL;
	temp = &n_list;
	while (lst)
	{
		ft_lstadd(temp, f(lst));
		lst = lst->next;
		temp = &((*temp)->next);
	}
	return (n_list);
}
