/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:37:53 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 19:23:13 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptrb;
	size_t	counter;

	ptrb = b;
	counter = 0;
	while (counter < len)
		*(ptrb + counter++) = (unsigned char)c;
	return (b);
}
