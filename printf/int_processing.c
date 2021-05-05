/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:16:16 by kcraster          #+#    #+#             */
/*   Updated: 2021/01/12 17:12:42 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	int_printing(t_list *pnt, char *str, int length)
{
	if (pnt->flag_null > 0)
	{
		pnt->spaces = 0;
		pnt->nulls = pnt->width - length;
	}
	counting_characters(pnt, length);
	while (pnt->flag_minus == 0 && pnt->spaces-- > 0)
		write(1, " ", 1);
	if (str[0] == '-' && pnt->nulls > 0)
	{
		write(1, "-", 1);
		str++;
	}
	while (pnt->nulls-- > 0)
		write(1, "0", 1);
	if (pnt->type == 'p')
		write(1, "0x", 2);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	while (pnt->flag_minus > 0 && pnt->spaces-- > 0)
		write(1, " ", 1);
	free(str);
}

void		int_processing(t_list *pnt, char *str, int length)
{
	if (pnt->dot > 0 && pnt->precision == 0 && *str == '0')
	{
		str = "";
		length = 0;
		if (pnt->type == 'p')
			length += 2;
	}
	pnt->nulls = pnt->precision - length;
	pnt->spaces = pnt->width - length;
	if (pnt->width < pnt->precision || pnt->width == pnt->precision)
	{
		pnt->nulls = pnt->precision - length;
		pnt->spaces = 0;
	}
	if (pnt->precision > length)
		pnt->spaces = pnt->width - pnt->precision;
	if (str[0] == '-' && pnt->nulls > 0)
	{
		pnt->nulls += 1;
		pnt->spaces -= 1;
	}
	int_printing(pnt, str, length);
}
