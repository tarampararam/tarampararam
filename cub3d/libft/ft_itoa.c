/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:57:07 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/08 13:37:27 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_n(unsigned int n)
{
	int len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char			*s;
	unsigned int	i;
	unsigned int	len;
	unsigned int	nb;

	nb = (n < 0 ? -n : n);
	i = 0;
	len = len_n(nb);
	if (!(s = (char *)malloc(sizeof(char) * len + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		s[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		s[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	s[i] = 48 + (nb % 10);
	s[len] = '\0';
	return (s);
}
