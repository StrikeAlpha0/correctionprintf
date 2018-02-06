/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfspecify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:01:59 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/02 20:39:15 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printfspecify(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	int q;

	if ((q = ft_strstr((info->flag), "hh")) && q == 1)
		ft_putnbr(((signed char)(va_arg(*list, int))), info, pass);
	else if ((q = ft_strstr((info->flag), "h")) && q == 1)
		ft_putnbr(((short int)(va_arg(*list, int))), info, pass);
	else if ((q = ft_strstr((info->flag), "ll")) && q == 1)
		ft_putnbr((va_arg(*list, long long)), info, pass);
	else if ((q = ft_strstr((info->flag), "l")) && q == 1)
		ft_putnbr((va_arg(*list, long int)), info, pass);
	else if ((q = ft_strstr((info->flag), "j")) && q == 1)
		ft_putnbr((va_arg(*list, intmax_t)), info, pass);
	else if ((q = ft_strstr((info->flag), "z")) && q == 1)
		ft_putnbr((va_arg(*list, size_t)), info, pass);
	else
		ft_per_doi(list, info, pass);
}

void		ft_printfspecify1(va_list *list, t_inputinfo *info,
		t_passinfo *pass)
{
	int q;

	if ((q = ft_strstr((info->flag), "hh")) && q == 1)
		ft_putnbrup(((unsigned char)(va_arg(*list, int))), info, pass);
	else if ((q = ft_strstr((info->flag), "h")) && q == 1)
		ft_putnbrup(((unsigned short int)(va_arg(*list, int))), info, pass);
	else if ((q = ft_strstr((info->flag), "ll")) && q == 1)
		ft_putnbrup((va_arg(*list, unsigned long long)), info, pass);
	else if ((q = ft_strstr((info->flag), "l")) && q == 1)
		ft_putnbrup(((va_arg(*list, unsigned long))), info, pass);
	else if ((q = ft_strstr((info->flag), "j")) && q == 1)
		ft_putnbrup((va_arg(*list, intmax_t)), info, pass);
	else if ((q = ft_strstr((info->flag), "z")) && q == 1)
		ft_putnbrup((va_arg(*list, size_t)), info, pass);
	else
		ft_per_u(list, info, pass);
}
