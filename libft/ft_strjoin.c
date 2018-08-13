/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 20:15:27 by sechang           #+#    #+#             */
/*   Updated: 2018/08/03 00:49:30 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	newstr = 0;
	if (s1 && s2)
		newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) \
		+ ft_strlen(s2) + 1));
	if (!newstr)
		return (0);
	else
	{
		ft_strcpy(newstr, s1);
		ft_strcat(newstr, s2);
		return (newstr);
	}
	return (0);
}
