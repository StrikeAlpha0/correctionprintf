/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:37:57 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/04 19:17:56 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_hex(unsigned long nbr, t_inputinfo *info, t_passinfo *pass)
{
	char *hex;
	char i;

	if (info->flag[info->f] == '#' && info->hexswi == 0)
	{
		pass->strlen = -2;
		ft_flag_hash(nbr, info, pass);
		info->hexswi = 1;
	}
	i = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		ft_print_hex((nbr / 16), info, pass);
	i = nbr % 16;
	write(1, hex + i, 1);
	pass->final_count++;
	return (nbr);
}
