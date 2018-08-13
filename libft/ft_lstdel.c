/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:00:47 by sechang           #+#    #+#             */
/*   Updated: 2018/07/18 18:42:04 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*node;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		node = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = node;
	}
	*alst = NULL;
	return ;
}
