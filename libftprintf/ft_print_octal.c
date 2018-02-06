/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:37:57 by msharpe           #+#    #+#             */
/*   Updated: 2018/01/31 11:51:32 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_octal(unsigned long nbr, t_inputinfo *info, t_passinfo *pass)
{
	char *octal;
	char i;

	if (info->flag[info->f] == '#' && info->hexswi == 0)
	{
		pass->strlen = -1;
		ft_flag_hash(nbr, info, pass);
		info->hexswi = 1;
	}
	i = 0;
	octal = "01234567";
	if (nbr >= 8)
		ft_print_octal((nbr / 8), info, pass);
	i = nbr % 8;
	write(1, octal + i, 1);
	pass->final_count++;
	return (nbr);
}
