/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wput_strup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:38:50 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/02 23:44:13 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_wputchar(wchar_t c)
{
	write(1, &c, 1);
}

void		ft_wput_strup(wchar_t *s)
{
	int i;

	i = 0;
	while (s + i != NULL && *(s + i) != '\0')
	{
		ft_wputchar(*(s + i));
		i++;
	}
}
