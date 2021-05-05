/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:36:27 by kcraster          #+#    #+#             */
/*   Updated: 2021/01/12 17:13:49 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		int_regulations(t_list *pnt)
{
	int		n;
	int		length;
	char	*str;

	n = va_arg(pnt->ap, int);
	str = ft_itoa(n);
	length = ft_strlen(str);
	int_processing(pnt, str, length);
}

static void		u_regulations(t_list *pnt)
{
	unsigned int		n;
	int					length;
	char				*str;

	n = va_arg(pnt->ap, unsigned int);
	str = ft_itoa(n);
	length = ft_strlen(str);
	int_processing(pnt, str, length);
}

static void		hex_regulations(t_list *pnt)
{
	long long unsigned 	n;
	int					length;
	char				*str;
	n = va_arg(pnt->ap, long long unsigned);
	str = ft_itoa_hex(n, pnt);
	length = ft_strlen(str);
	if (pnt->type == 'p')
		length += 2;
	int_processing(pnt, str, length);
}

static void		string_char_regulations(t_list *pnt)
{
	int		n;
	int		length;
	char	*str;

	n = 0;
	if (pnt->type == 's')
	{
		str = va_arg(pnt->ap, char *);
		if (str == NULL)
		{
			str = ft_calloc(7, sizeof(char));
			str = "(null)";
		}
		length = ft_strlen(str);
		string_processing(pnt, str, length);

	}
	if (pnt->type == 'c')
	{
		n = va_arg(pnt->ap, int);
		length = 1;
		str = NULL;
		char_processing(pnt, n, length);
	}
	if (pnt->type == '%')
		percent_processing(pnt);
}

int				processing(t_list *pnt)
{
	if (pnt->width < 0)
	{
		pnt->flag_minus = 1;
		pnt->flag_null = 0;
		pnt->width = pnt->width * (-1);
	}
	if (pnt->precision > 0 && (pnt->type == 'd' || pnt->type == 'i' ||
		pnt->type == 'x' || pnt->type == 'X' || pnt->type == 'u'))
		pnt->flag_null = 0;
	if (pnt->type == 'd' || pnt->type == 'i')
		int_regulations(pnt);
	if (pnt->type == 'x' || pnt->type == 'X' || pnt->type == 'p')
		hex_regulations(pnt);
	if (pnt->type == 'u')
		u_regulations(pnt);
	if (pnt->type == 's' || pnt->type == 'c' || pnt->type == '%')
		string_char_regulations(pnt);
	return (0);
}
