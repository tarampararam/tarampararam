/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:40 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/12 17:43:25 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (n--)
	{
		b[i] = a[i];
		if (a[i] == (unsigned char)c)
			return ((void *)b + i + 1);
		i++;
	}
	return (NULL);
}
