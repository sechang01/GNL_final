/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:37:33 by sechang           #+#    #+#             */
/*   Updated: 2018/07/18 23:40:23 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			counter;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	counter = 0;
	while (counter < n)
	{
		*(pdst + counter) = *(psrc + counter);
		if (*(psrc + counter) == (unsigned char)c)
			return ((void *)(pdst + counter + 1));
		counter++;
	}
	return (NULL);
}
