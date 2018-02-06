/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:29:01 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/05 18:50:07 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		p_suite(long n, t_inputinfo *info, t_passinfo *pass)
{
	{
		if (info->precision > pass->width)
			pass->width = info->precision;
		if (info->precision == pass->width)
		{
			if (ft_strstr((info->flag), " ") == 1)
			{
				pass->numlen--;
				ft_flag_zero(n, info, pass);
			}
		}
		else if ((pass->width - info->precision) > 0)
		{
			while ((pass->width - info->precision) > 0)
			{
				ft_putchar(' ');
				pass->width--;
			}
		}
	}
}

void			ft_putnbr(long n, t_inputinfo *info, t_passinfo *pass)
{
	info->swi = 0;
	info->f = 0;
	info->z = 1;
	ft_frontloadflag(n, info, pass);
	info->f = 0;
	while (info->flag[info->f] != '-' && info->flag[info->f] != '\0' &&
			info->flag[info->f] != '0')
		info->f++;
	if (info->precision > 0)
		p_suite(n, info, pass);
	if (info->flag[info->f] == '\0' && pass->numlen < pass->width
			&& pass->width > info->precision)
	{
		info->swi = 2;
		ft_flag_space(n, info, pass);
	}
	ft_midloadflag(n, info, pass);
	if (n < 0)
		n = -n;
	ft_putnbrup(n, info, pass);
	ft_backloadflag(n, info, pass);
}
