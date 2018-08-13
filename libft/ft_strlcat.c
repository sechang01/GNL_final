/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 08:07:35 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 20:59:42 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	c;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	c = 0;
	if (dstsize < dst_len)
		return (dstsize + src_len);
	while (src[c] && (dst_len + c + 1) < dstsize)
	{
		dst[dst_len + c] = src[c];
		c++;
	}
	dst[dst_len + c] = '\0';
	return (dst_len + src_len);
}
