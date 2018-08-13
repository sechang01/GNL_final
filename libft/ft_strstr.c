/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:04:39 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 22:13:39 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (haystack[i])
	{
		while (haystack[i + needle_begin] == needle[needle_begin])
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
