/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:07:53 by msharpe           #+#    #+#             */
/*   Updated: 2018/01/29 22:44:19 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int it;
	int size;
	int j;

	i = 0;
	size = ft_strlen(haystack);
	it = ft_strlen(needle);
	if (it == 0)
		return (0);
	while (i < size - it + 1)
	{
		j = 0;
		while (j < it)
		{
			if (haystack[i + j] != needle[j])
				break ;
			if (j == it - 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
