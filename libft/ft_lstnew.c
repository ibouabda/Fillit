/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:20:08 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/28 14:49:02 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		content_size = 0;
	}
	else
	{
		if (!(newlist->content = malloc(content_size)))
			return (NULL);
		newlist->content_size = content_size;
		ft_memcpy(newlist->content, content, content_size);
	}
	newlist->next = NULL;
	return (newlist);
}
