/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfwriter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:09:03 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/04 23:51:04 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_per_s(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	pass->numlen = -1;
	ft_putstr(va_arg(*list, char *), info, pass);
}

void		ft_per_c(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	ft_putchar((char)va_arg(*list, int));
	info->count++;
	pass->final_count++;
}

void		ft_per_per(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	void *nns;

	nns = list;
	info->f = 0;
	ft_putchar('%');
	pass->final_count++;
}

void		ft_per_supr(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	pass->numlen = -1;
	ft_putstrup((char *)va_arg(*list, wchar_t *), info, pass);
}

void		ft_per_q(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	pass->numlen = -1;
	ft_cryptoputstr(va_arg(*list, char *), info, pass);
}
