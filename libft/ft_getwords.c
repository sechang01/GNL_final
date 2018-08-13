/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 10:48:05 by sechang           #+#    #+#             */
/*   Updated: 2018/07/21 13:00:07 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_getwords(char const *s, char c)
{
	int		wordcount;
	char	**newarr;

	wordcount = 0;
	while (*s)
	{
		if (((*s != c) && (*(s + 1) == c)) || ((*s != c) && (*(s + 1) == '\0')))
			wordcount++;
		s++;
	}
	if (!(newarr = (char **)malloc(sizeof(char *) * (wordcount + 1))))
		return (NULL);
	*(newarr + wordcount) = NULL;
	return (newarr);
}
