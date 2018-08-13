/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 08:51:35 by sechang           #+#    #+#             */
/*   Updated: 2018/07/21 08:11:10 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		trimmarker1;
	size_t		trimmarker2;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (ft_iswhitespace(s[i]))
	{
		i++;
		if (!s[i])
			return (ft_strnew(1));
	}
	trimmarker1 = i;
	while (s[i])
		i++;
	i--;
	while (ft_iswhitespace(s[i]))
		i--;
	i++;
	trimmarker2 = i;
	return (ft_strsub(s, (unsigned int)trimmarker1, \
	(trimmarker2 - trimmarker1)));
}
