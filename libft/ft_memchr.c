/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:41:24 by sechang           #+#    #+#             */
/*   Updated: 2018/07/18 18:43:19 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrs;
	size_t			counter;

	ptrs = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (*(ptrs + counter) == (unsigned char)c)
			return (ptrs + counter);
		counter++;
	}
	return (0);
}
