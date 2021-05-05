/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:54:08 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/12 14:39:37 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((*((unsigned char *)s++)) == (unsigned char)c)
			return ((void *)s - 1);
	}
	return (0);
}
