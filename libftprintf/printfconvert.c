/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:30:09 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/02 20:34:10 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_per_x(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	info->f = 0;
	ft_print_hex(va_arg(*list, unsigned int), info, pass);
}

void			ft_per_xup(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	info->f = 0;
	ft_print_hexup(va_arg(*list, unsigned int), info, pass);
}

void			ft_per_o(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	info->f = 0;
	ft_print_octal(va_arg(*list, unsigned int), info, pass);
}

void			ft_per_oup(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	info->f = 0;
	ft_print_octal(va_arg(*list, unsigned int), info, pass);
}

void			ft_per_p(va_list *list, t_inputinfo *info, t_passinfo *pass)
{
	info->f = 0;
	ft_print_address(va_arg(*list, unsigned long), info, pass);
}
