/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 20:04:06 by kcraster          #+#    #+#             */
/*   Updated: 2021/01/12 17:13:33 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		percent_processing(t_list *pnt)
{
	if (pnt->flag_null > 0)
	{
		pnt->nulls = pnt->width - 1;
		counting_characters(pnt, 1);
		while (pnt->nulls-- > 0)
			write(1, "0", 1);
	}
	else
	{
		pnt->spaces = pnt->width - 1;
		counting_characters(pnt, 1);
	}
	if (pnt->flag_minus == 0 && pnt->flag_null == 0)
	{
		while (pnt->spaces-- > 0 && pnt->width > 0)
			write(1, " ", 1);
	}
	write(1, "%", 1);
	while (pnt->spaces-- > 0 && pnt->flag_minus > 0)
		write(1, " ", 1);
}
