/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:08:30 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/04 22:41:38 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_wput2(wchar_t const *s, t_inputinfo *info,
		t_passinfo *pass, int i)
{
	while (s + i != NULL && *(s + i) != '\0' && info->p < info->precision)
	{
		ft_wputchar(*(s + i));
		i++;
		info->p++;
		pass->final_count++;
	}
	while (i < pass->width)
	{
		ft_putchar(' ');
		i++;
	}
}

void			ft_wputstr(wchar_t const *s, t_inputinfo *info,
		t_passinfo *pass)
{
	int i;
	int n;
	int q;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	n = ft_wstrlen(s);
	info->f = 0;
	if (info->precision == 0)
		ft_wput_strup((wchar_t *)s);
	else if (info->precision > 0)
		ft_wput2(s, info, pass, i);
	ft_backloadflag(n, info, pass);
	if ((q = ft_strstr((info->flag), "-")) && q == 1)
	{
		pass->numlen = -1;
		ft_flag_minus(*s, info, pass);
	}
}
