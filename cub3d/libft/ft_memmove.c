/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:46:36 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/12 14:37:37 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	if (csrc < cdst)
	{
		while (i++ < len)
		{
			cdst[len - i] = csrc[len - i];
		}
	}
	i = 0;
	if (csrc > cdst)
	{
		while (len-- > 0)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (cdst);
}
