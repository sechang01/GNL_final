/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:51:20 by sechang           #+#    #+#             */
/*   Updated: 2018/07/18 14:51:47 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr_s1;
	char	*ptr_s2;
	size_t	counter;

	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (*(ptr_s1 + counter) != *(ptr_s2 + counter))
		{
			return ((unsigned char)*(ptr_s1 + counter)) \
			- ((unsigned char)*(ptr_s2 + counter));
		}
		counter++;
	}
	return (0);
}
