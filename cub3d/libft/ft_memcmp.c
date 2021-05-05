/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:55:00 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/01 19:38:54 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *a;
	unsigned char *b;
	unsigned long c;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	c = 0;
	while (c < n)
	{
		if (a[c] != b[c])
		{
			return (a[c] - b[c]);
		}
		c++;
	}
	return (0);
}
