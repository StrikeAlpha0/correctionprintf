/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrrot13.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:47:34 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/05 00:18:39 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putcharrot(unsigned char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
	{
		c = c + 13;
		write(1, &c, 1);
	}
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
	{
		c = c - 13;
		write(1, &c, 1);
	}
	else if ((c >= 32 && c <= 47))
	{
		c = c + 16;
		write(1, &c, 1);
	}
	else if ((c >= 48 && c <= 63))
	{
		c = c - 16;
		write(1, &c, 1);
	}
}

void		ft_putstrrot13(const char *s, t_inputinfo *info, t_passinfo *pass)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putcharrot(s[i]);
		i++;
		pass->final_count++;
	}
	info->count++;
}
