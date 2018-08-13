/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:04:22 by sechang           #+#    #+#             */
/*   Updated: 2018/07/22 17:21:09 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**arr_split;
	int		wordstart;
	int		k;
	int		i;

	if (!s)
		return (NULL);
	k = 0;
	i = 0;
	wordstart = -1;
	if (!(arr_split = ft_getwords(s, c)))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && wordstart == -1)
			wordstart = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr_split[k++] = ft_strsub(s, wordstart, (i - wordstart + 1));
			wordstart = -1;
		}
		i++;
	}
	return (arr_split);
}
