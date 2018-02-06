/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cryptoputstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:15:22 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/05 20:02:20 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_crypto2(const char *s, t_inputinfo *info,
		t_passinfo *pass, int i)
{
	while (s + i != NULL && *(s + i) != '\0' && info->p < info->precision)
	{
		ft_putcharrot(*(s + i));
		i++;
		info->p++;
		pass->final_count++;
	}
	while (i < pass->width - 1)
	{
		ft_putcharrot(' ');
		i++;
		pass->final_count++;
	}
}

static void		basesetup(const char *s, t_inputinfo *info, t_passinfo *pass)
{
	while (pass->strlen > 0)
	{
		ft_base64(((unsigned char *)s), info, pass);
		s += 3;
		pass->strlen -= 3;
	}
}

void			ft_cryptoputstr(char const *s, t_inputinfo *info,
		t_passinfo *pass)
{
	int	i;
	int q;

	q = 0;
	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		pass->final_count += 6;
		return ;
	}
	pass->strlen = ft_strlen(s);
	info->f = 0;
	if (info->precision == 0)
	{
		if (g_spec_table[info->tsearch].name == 'q')
			ft_putstrrot13(s, info, pass);
		if (g_spec_table[info->tsearch].name == 'b')
			basesetup(((const char *)s), info, pass);
	}
	else if (info->precision > 0)
		ft_crypto2(s, info, pass, i);
	if (ft_strstr((info->flag), "-") == 1)
		ft_flag_minus(*s, info, pass);
}
