/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frontloadflag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:27:37 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/02 20:21:41 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_frontloadflag(long n, t_inputinfo *info, t_passinfo *pass)
{
	int x;

	x = 0;
	if (n < 0)
	{
		n = -n;
		pass->numlen++;
		info->swi = 1;
		x = 1;
	}
	pass->numlen += ft_numlen(n);
	info->f = 0;
	while (info->flag[info->f] != '\0')
	{
		if (info->flag[info->f] == ' ')
			ft_flag_space(n, info, pass);
		if (info->flag[info->f] == '+' && x == 0)
			ft_flag_plus(n, info, pass);
		info->f++;
	}
}
