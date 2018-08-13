/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:06:14 by sechang           #+#    #+#             */
/*   Updated: 2018/08/04 17:46:55 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;
	size_t	counter;

	pdst = (char *)dst;
	psrc = (char *)src;
	counter = 0;
	while (counter < n)
	{
		*(pdst + counter) = *(psrc + counter);
		counter++;
	}
	return (dst);
}
