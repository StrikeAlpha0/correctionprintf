/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:42:31 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/05 00:33:06 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		p_suite(char const *s, t_inputinfo *info,
		t_passinfo *pass, int i)
{
	while (s + i != NULL && *(s + i) != '\0' && info->p < info->precision)
	{
		ft_putchar(*(s + i));
		i++;
		info->p++;
		pass->final_count++;
	}
	while (i < pass->width - 1)
	{
		ft_putchar(' ');
		i++;
		pass->final_count++;
	}
}

void			ft_putstr(char const *s, t_inputinfo *info, t_passinfo *pass)
{
	int i;
	int q;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	pass->strlen = ft_strlen(s);
	info->f = 0;
	if (info->precision == 0)
		ft_putstrup(s, info, pass);
	else if (info->precision > 0)
		p_suite(s, info, pass, i);
	if ((q = ft_strstr((info->flag), "-")) && q == 1)
		ft_flag_minus(*s, info, pass);
}
