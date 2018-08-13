/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 06:59:15 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 07:18:05 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t counter;
	size_t src_len;

	counter = 0;
	src_len = ft_strlen((char *)src);
	while (counter < len)
	{
		if (counter > src_len)
			dst[counter] = '\0';
		else
			dst[counter] = src[counter];
		counter++;
	}
	return (dst);
}
