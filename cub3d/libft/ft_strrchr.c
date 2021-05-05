/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:38:27 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/03 12:29:05 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if ((char)c == 0)
		return ((char *)s + len);
	while (len--)
		if (*(s + len) == c)
			return ((char *)(s + len));
	return (0);
}
