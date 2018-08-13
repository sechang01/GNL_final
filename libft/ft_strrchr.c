/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 08:55:53 by sechang           #+#    #+#             */
/*   Updated: 2018/07/21 08:09:38 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;

	counter = 0;
	while (*s)
	{
		s++;
		counter++;
	}
	if (c == '\0')
		return ((char *)s);
	while (counter >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		counter--;
	}
	return (NULL);
}
