/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:24:09 by sechang           #+#    #+#             */
/*   Updated: 2018/07/21 08:10:33 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		needle_len;
	int		needle_begin;

	i = 0;
	needle_len = 0;
	needle_begin = 0;
	while (needle[needle_len])
		needle_len++;
	if (needle_len == 0)
		return ((char *)haystack);
	while (i < (int)len && haystack[i])
	{
		while (haystack[i + needle_begin] == needle[needle_begin] &&\
		(i + needle_begin) < (int)len)
		{
			if (needle_begin == needle_len - 1)
				return ((char *)haystack + i);
			needle_begin++;
		}
		needle_begin = 0;
		i++;
	}
	return (0);
}
