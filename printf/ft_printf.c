/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:46:47 by kcraster          #+#    #+#             */
/*   Updated: 2021/01/12 17:13:28 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			counting_characters(t_list *pnt, int length)
{
	if (pnt->nulls < 0)
		pnt->nulls = 0;
	if (pnt->spaces < 0)
		pnt->spaces = 0;
	pnt->len = pnt->len + pnt->nulls + pnt->spaces + length;
}

int				ft_printf(const char *format, ...)
{
	int			i;
	t_list		pnt;

	pnt.len = 0;
	i = 0;
	va_start(pnt.ap, format);
	while (format[i] != '\0')
	{
		while (format[i] == '%')
		{
			i = parsing(format, &pnt, i + 1);
			if (format[i] == '\0')
				break ;
			i++;
		}
		if (format[i] == '\0')
			break ;
		write(1, &format[i], 1);
		i++;
		pnt.len++;
	}
	va_end(pnt.ap);
	return (pnt.len);
}
