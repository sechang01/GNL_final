/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:20:08 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 07:16:47 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*newstr;

	if (!s || !f)
		return (0);
	if (!(newstr = ft_strnew(ft_strlen(s))))
		return (0);
	i = 0;
	while (s[i])
	{
		newstr[i] = (*f)(s[i]);
		i++;
	}
	return (newstr);
}
