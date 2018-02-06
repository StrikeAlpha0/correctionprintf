/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:13:59 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/02 20:37:10 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_flag_plus(long n, t_inputinfo *info, t_passinfo *pass)
{
	if (n >= 0 && info)
	{
		ft_putchar('+');
		pass->numlen++;
	}
	info->swi++;
	pass->final_count++;
}

void			ft_flag_space(long n, t_inputinfo *info, t_passinfo *pass)
{
	if (n > 0 && info->swi == 0)
	{
		ft_putchar(' ');
		pass->numlen++;
		info->swi = 1;
		pass->final_count++;
	}
	else if (info->swi == 2)
	{
		while (pass->numlen < pass->width)
		{
			ft_putchar(' ');
			pass->numlen++;
			pass->final_count++;
		}
		info->swi = 3;
	}
}

void			ft_flag_minus(long n, t_inputinfo *info, t_passinfo *pass)
{
	if (pass->strlen == -1)
	{
		while (pass->numlen < pass->width)
		{
			ft_putchar(' ');
			pass->numlen++;
			pass->final_count++;
		}
		n = n * 1;
	}
	else if (pass->numlen == -1)
	{
		while (pass->strlen < pass->width)
		{
			ft_putchar(' ');
			pass->strlen++;
			pass->final_count++;
		}
	}
	info->count++;
}

void			ft_flag_zero(long n, t_inputinfo *info, t_passinfo *pass)
{
	while (pass->numlen < pass->width)
	{
		ft_putchar('0');
		pass->numlen++;
		pass->final_count++;
	}
	n = n * 1;
	info->count++;
}

void			ft_flag_hash(long n, t_inputinfo *info, t_passinfo *pass)
{
	if (pass->strlen == -1)
	{
		if (n != 0)
		{
			ft_putchar('0');
			pass->final_count++;
		}
	}
	if (pass->strlen == -2)
	{
		ft_putstr("0x", info, pass);
		pass->final_count += 2;
	}
	if (pass->strlen == -3)
	{
		ft_putstr("0X", info, pass);
		pass->final_count += 2;
	}
	n = n * 1;
}
