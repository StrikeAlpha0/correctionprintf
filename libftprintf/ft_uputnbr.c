/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:20:56 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/02 13:02:34 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnbrup(unsigned long n, t_inputinfo *info, t_passinfo *pass)
{
	if (info->z == 0)
	{
		ft_frontloadflag(n, info, pass);
		ft_midloadflag(n, info, pass);
	}
	if (n > 9)
	{
		if (info->z == 0)
			info->z = 2;
		ft_putnbrup(n / 10, info, pass);
		ft_putnbrup(n % 10, info, pass);
	}
	else
	{
		ft_putchar(n + '0');
		pass->final_count++;
	}
	if (info->z == 2)
	{
		ft_backloadflag(n, info, pass);
		info->z = 3;
	}
}
