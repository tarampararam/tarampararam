/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:26:57 by kcraster          #+#    #+#             */
/*   Updated: 2021/03/02 17:55:48 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_n_hex(long long unsigned n)
{
	unsigned int len;

	len = 0;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len + 1);
}

char			*ft_itoa_hex(long long unsigned n, t_list *pnt)
{
	char				*str;
	int					i;
	unsigned int		len;
	long long unsigned	nb;

	nb = n;
	i = 0;
	len = len_n_hex(nb);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		if ((nb % 16) >= 0 && (nb % 16) <= 9)
			str[i] = (nb % 16) + 48;
		if ((pnt->type == 'x' || pnt->type == 'p') && (((nb % 16 >= 10) && (nb % 16 <= 15))))
			str[i] = (nb % 16) + 'a' - 10;
		if (pnt->type == 'X' && (((nb % 16 >= 10) && (nb % 16 <= 15))))
			str[i] = (nb % 16) + 'A' - 10;
		nb /= 16;
		i--;
	}
	return (str);
}