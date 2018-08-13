/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 07:49:45 by sechang           #+#    #+#             */
/*   Updated: 2018/07/18 19:35:58 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	c;

	s1_len = ft_strlen(s1);
	c = 0;
	while (s2[c] && c < n)
	{
		s1[s1_len + c] = s2[c];
		c++;
	}
	s1[s1_len + c] = '\0';
	return (s1);
}
