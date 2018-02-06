/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfsystem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:14:39 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/05 15:05:16 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_address(unsigned long n, t_inputinfo *info, t_passinfo *pass)
{
	ft_putstr("0x", info, pass);
	ft_print_hex(n, info, pass);
}

void	ft_per_k(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	ft_wputstr(va_arg(*list, wchar_t *), info, pass);
}

void	ft_checkpoint(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	int q;

	if ((q = ft_strstr((info->flag), "l")) && q == 1)
		ft_wput_strup(va_arg(*list, wchar_t *));
	else
		ft_per_s(list, info, pass);
}
