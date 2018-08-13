/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:43:45 by sechang           #+#    #+#             */
/*   Updated: 2018/08/04 17:42:42 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int counter;

	counter = 0;
	while (src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (dst);
}
