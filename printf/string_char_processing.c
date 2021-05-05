/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_char_processing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:39:09 by kcraster          #+#    #+#             */
/*   Updated: 2021/01/12 17:12:35 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_processing(t_list *pnt, int n, int length)
{
	length = 1;
	pnt->spaces = pnt->width - length;
	counting_characters(pnt, length);
	if (pnt->flag_minus == 0)
	{
		if (pnt->width > 0)
		{
			while (pnt->spaces-- > 0)
				write(1, " ", 1);
		}
		if (pnt->type == 'c')
			write(1, &n, 1);
	}
	if (pnt->flag_minus > 0)
	{
		write(1, &n, 1);
		while (pnt->spaces-- > 0)
			write(1, " ", 1);
	}
}

void	string_processing(t_list *pnt, char *str, int length)
{
	pnt->spaces = pnt->width - length;
	if (pnt->dot > 0)
	{
		if (pnt->precision == 0)
			length = 0;
		if (pnt->precision > 0 && pnt->precision < length)
			length = pnt->precision;
		pnt->spaces = pnt->width - length;
	}
	counting_characters(pnt, length);
	if (pnt->flag_minus == 0)
		while (pnt->spaces-- > 0)
			write(1, " ", 1);
	while (length-- > 0)
	{
		write(1, str, 1);
		str++;
	}
	if (pnt->flag_minus > 0)
		while (pnt->spaces-- > 0)
			write(1, " ", 1);
	free(str);
}
