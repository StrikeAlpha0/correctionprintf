/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfmulti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:52:55 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/04 22:41:03 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_flag_period(long n, t_inputinfo *info, t_passinfo *pass)
{
	n = 1;
	info->f++;
	if (info->flag[info->f] >= '0' && info->flag[info->f] <= '9')
	{
		info->precision = ft_atoi(info->flag + info->f);
		while (info->flag[info->f] >= '0' && info->flag[info->f] <= '9')
			info->f++;
	}
	n = n * 1;
	pass->count++;
}
