/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:43:35 by sechang           #+#    #+#             */
/*   Updated: 2018/08/04 17:42:26 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new_str == 0)
		return (0);
	else
		return (ft_strcpy(new_str, s1));
}
