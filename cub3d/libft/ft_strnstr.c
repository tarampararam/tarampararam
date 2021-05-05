/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:15:35 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/12 13:03:40 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!haystack && !needle)
		return (0);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len--)
	{
		if (ft_strlen(needle) <= len + 1)
			if (!(ft_strncmp(haystack, needle, ft_strlen(needle))))
				return ((char *)haystack);
		haystack++;
	}
	return (0);
}
