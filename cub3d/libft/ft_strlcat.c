/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:20:33 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/09 13:56:17 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	srclen;

	len = 0;
	srclen = ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dst++;
		len++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize == 1 || *src == 0)
		*dst = '\0';
	return (srclen + len);
}
