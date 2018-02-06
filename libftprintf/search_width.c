/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 21:20:40 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/03 02:22:00 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void		search_precision(va_list *list, const char *format,
		t_inputinfo *info, t_passinfo *pass)
{
	void *nns;

	nns = list;
	if (info->x >= 1)
		return ;
	if (format[info->i] >= '1' && format[info->i] <= '9')
	{
		info->precision = ft_atoi(format + info->i);
		while (format[info->i] >= '0' && format[info->i] <= '9')
			info->i++;
	}
	pass->count++;
}

void		search_width(va_list *list, const char *format,
		t_inputinfo *info, t_passinfo *pass)
{
	if (info->x >= 1)
		return ;
	if (format[info->i] >= '1' && format[info->i] <= '9')
	{
		pass->width = ft_atoi(format + info->i);
		while (format[info->i] >= '0' && format[info->i] <= '9')
			info->i++;
		if (format[info->i] == '.')
		{
			info->i++;
			search_precision(list, format, info, pass);
		}
		search_specs(list, format, info, pass);
		info->y++;
	}
	spec_table(list, format, info, pass);
}
