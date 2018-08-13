/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:27:07 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 17:59:19 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		node->content = 0;
		content_size = 0;
	}
	else
	{
		if (!(node->content = (void *)malloc(content_size)))
			return (NULL);
		node->content = ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
