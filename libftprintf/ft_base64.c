/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:37:57 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/05 20:03:17 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_base64(unsigned char *c, t_inputinfo *info, t_passinfo *pass)
{
	int in[3];
	int out[4];
	int num;

	in[0] = c[0];
	in[1] = pass->strlen >= 2 ? c[1] : 0;
	in[2] = pass->strlen >= 3 ? c[2] : 0;
	num = in[0] << 16;
	num |= in[1] << 8;
	num |= in[2] << 0;
	info->v = 4;
	while (info->v--)
	{
		out[info->v] = info->key[num % 64];
		num /= 64;
	}
	info->v = 0;
	while (info->v < 4)
	{
		if (pass->strlen < info->v)
			write(1, "=", 1);
		else
			write(1, &out[info->v], 1);
		info->v++;
	}
}
