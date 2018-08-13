/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:39:17 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 17:35:24 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	counter;

	pdst = (char *)dst;
	psrc = (char *)src;
	counter = 0;
	if (pdst > psrc)
		while ((int)--len >= 0)
		{
			pdst[len] = psrc[len];
		}
	else
		while (counter < len)
		{
			pdst[counter] = psrc[counter];
			counter++;
		}
	return ((void*)(pdst));
}
