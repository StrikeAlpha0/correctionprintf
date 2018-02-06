/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:53:12 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/05 18:11:26 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

/*
** Table: d:print int digits, D:long ints, i:print int digits, u:unsigned int
** U:unsigned long int, o:octal conversion, O:long octal conversion,
** x:lowercase hex X:uppercase hex, c:print char, C:print wide char,
** s:print string, S:print wide string, p:print address, %:print a %,
** q:rot13, b:base64.
*/

/*
** use atoi to use 0;0;0m format for 256 color support
*/

t_printf_struct		g_spec_table[] =
{
	{'d', ft_per_doi},
	{'D', ft_per_dup},
	{'i', ft_per_doi},
	{'u', ft_per_u},
	{'U', ft_per_uup},
	{'o', ft_per_o},
	{'O', ft_per_oup},
	{'x', ft_per_x},
	{'X', ft_per_xup},
	{'c', ft_per_c},
	{'C', ft_per_c},
	{'s', ft_per_s},
	{'S', ft_per_s},
	{'p', ft_per_p},
	{'%', ft_per_per},
	{'q', ft_per_q},
	{'k', ft_per_k},
	{'b', ft_per_q}
};
/*
** Suffix addition of spaces, prefix addition of +/-, prefix:space,
** prefix of zero for octal/hex, prefix:0's
*/
t_printfflag_struct g_flag_table[] =
{
	{'-', ft_flag_minus},
	{'+', ft_flag_plus},
	{' ', ft_flag_space},
	{'#', ft_flag_hash},
	{'0', ft_flag_zero},
	{'.', ft_flag_period}
};

t_printfcast_struct g_cast_table[] =
{
	{'h', ft_printfspecify},
	{'l', ft_printfspecify},
	{'j', ft_printfspecify},
	{'z', ft_printfspecify}
};

void				spec_table(va_list *list, const char *format,
		t_inputinfo *info, t_passinfo *pass)
{
	if (info->y >= 1)
		return ;
	info->tsearch = 0;
	while (format[info->i] != g_spec_table[info->tsearch].name &&
			g_spec_table[info->tsearch].name != '\0')
		info->tsearch++;
	if (g_spec_table[info->tsearch].name == 'd' ||
			g_spec_table[info->tsearch].name == 'i')
		ft_printfspecify(list, info, pass);
	else if (g_spec_table[info->tsearch].name == 'u')
		ft_printfspecify1(list, info, pass);
	else if (g_spec_table[info->tsearch].name == 's')
		ft_checkpoint(list, info, pass);
	else if (format[info->i] == g_spec_table[info->tsearch].name &&
			g_spec_table[info->tsearch].name != '\0')
		g_spec_table[info->tsearch].function(list, info, pass);
	else
		ft_putchar(format[info->i]);
	info->i++;
}

void				search_specs(va_list *list, const char *format,
		t_inputinfo *info, t_passinfo *pass)
{
	info->tsearch = 0;
	info->cast = 0;
	while (format[info->i] != g_cast_table[info->cast].name &&
			g_cast_table[info->cast].name != '\0')
		info->cast++;
	if (format[info->i] == g_cast_table[info->cast].name &&
			g_cast_table[info->cast].name != '\0')
	{
		info->flag[info->f++] = format[info->i++];
		search_specs(list, format, info, pass);
		info->x = 1;
	}
	while (format[info->i] != g_flag_table[info->tsearch].name &&
			g_flag_table[info->tsearch].name != '\0')
		info->tsearch++;
	if (format[info->i] == g_flag_table[info->tsearch].name &&
			g_flag_table[info->tsearch].name != '\0')
	{
		info->flag[info->f++] = format[info->i++];
		search_specs(list, format, info, pass);
		info->x = 1;
	}
	search_width(list, format, info, pass);
}

static void			ft_colors(const char *format, t_inputinfo *info,
		t_passinfo *pass)
{
	int		q;

	q = 0;
	if ((q = ft_strstr(format, "red")) && q == 1)
		ft_putstrup("\x1b[31m", info, pass);
	else if ((q = ft_strstr(format, "green")) && q == 1)
		ft_putstrup("\x1b[32m", info, pass);
	else if ((q = ft_strstr(format, "yellow")) && q == 1)
		ft_putstrup("\x1b[33m", info, pass);
	else if ((q = ft_strstr(format, "blue")) && q == 1)
		ft_putstrup("\x1b[34m", info, pass);
	else if ((q = ft_strstr(format, "magenta")) && q == 1)
		ft_putstrup("\x1b[35m", info, pass);
	else if ((q = ft_strstr(format, "cyan")) && q == 1)
		ft_putstrup("\x1b[36m", info, pass);
	else if ((q = ft_strstr(format, "white")) && q == 1)
		ft_putstrup("\x1b[37m", info, pass);
	else if ((q = ft_strstr(format, "secret")) && q == 1)
		ft_putstrup("\x1b[30m", info, pass);
	while (format[info->i] != '\0' && format[info->i] != '}')
		info->i++;
	info->i++;
}

static void			reset(t_inputinfo *info, t_passinfo *pass)
{
	pass->width = 0;
	info->f = 0;
	ft_bzero(info->flag, 10);
	info->tsearch = 0;
	info->x = 0;
	info->swi = 0;
	pass->numlen = 0;
	info->cast = 0;
	info->y = 0;
	info->precision = 0;
	info->z = 0;
	info->p = 0;
}

int					ft_printf(const char *format, ...)
{
	va_list		list;
	t_passinfo	pass;
	t_inputinfo input;

	initialize_it_all(&pass, &input);
	va_start(list, format);
	while (format[input.i] != '\0')
	{
		if (format[input.i] == '{')
			ft_colors(format, &input, &pass);
		if (format[input.i] == '%')
		{
			input.i++;
			input.search = format[input.i];
			search_specs(&list, format, &input, &pass);
			reset(&input, &pass);
		}
		else
		{
			ft_putchar(format[input.i++]);
			pass.final_count++;
		}
	}
	va_end(list);
	return (pass.final_count);
}
