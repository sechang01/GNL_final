/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:56:43 by sechang           #+#    #+#             */
/*   Updated: 2018/07/20 17:35:40 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int			i;
	int			nbr;
	int			neg;
	int			numcheck;

	i = 0;
	nbr = 0;
	neg = 0;
	numcheck = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\f' ||\
	s[i] == '\v' || s[i] == '\r')
		i++;
	if (s[i] == '-')
		neg = 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		if (numcheck >= 19)
			return ((neg == 1) ? 0 : (-1));
		nbr *= 10;
		nbr += s[i++] - '0';
		numcheck++;
	}
	return ((neg == 1) ? (-nbr) : (nbr));
}
