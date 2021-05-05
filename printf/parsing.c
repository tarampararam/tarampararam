/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:35:11 by kcraster          #+#    #+#             */
/*   Updated: 2021/01/09 17:40:54 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		zero_values(t_list *pnt)
{
	pnt->flag_minus = 0;
	pnt->flag_null = 0;
	pnt->width = 0;
	pnt->precision = 0;
	pnt->dot = 0;
	pnt->percent = 0;
	pnt->type = 0;
	pnt->spaces = 0;
	pnt->nulls = 0;
	return (1);
}

static int		flag_parsing(const char *format, t_list *pnt, int i)
{
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			pnt->flag_minus = 1;
		if (format[i] == '0')
			pnt->flag_null = 1;
		i++;
	}
	return (i);
}

static int		width_parsing(const char *format, t_list *pnt, int i)
{
	if (format[i] == '*')
	{
		pnt->width = va_arg(pnt->ap, int);
		i++;
	}
	else
		pnt->width = ft_atoi(&format[i]);
	while (ft_isdigit_pf(format, i))
		i++;
	return (i);
}

static int		precision_parsing(const char *format, t_list *pnt, int i)
{
	i++;
	if (format[i] == '*')
	{
		pnt->precision = va_arg(pnt->ap, int);
		i++;
	}
	else
		pnt->precision = ft_atoi(&format[i]);
	while (ft_isdigit_pf(format, i))
		i++;
	return (i);
}

int		parsing(const char *format, t_list *pnt, int i)
{
	zero_values(pnt);
	if (format[i] == '-' || format[i] == '0')
	{
		i = flag_parsing(format, pnt, i);
		if (pnt->precision > 0)
			pnt->flag_null = 0;
		if (pnt->flag_minus > 0)
			pnt->flag_null = 0;
	}
	if (ft_isdigit_pf(format, i) || format[i] == '*')
		i = width_parsing(format, pnt, i);
	if (format[i] == '.')
	{
		pnt->dot = 1;
		i = precision_parsing(format, pnt, i);
	}
	if (ft_isalpha_pf(format, i))
		pnt->type = format[i];
	processing(pnt);
	return (i);
}
