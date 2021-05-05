/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:45:18 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/11 18:45:06 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	i = start;
	if (!s)
		return (0);
	while (s[i] != 0 && len--)
		i++;
	l = i - start + 1;
	if (ft_strlen(s) <= start)
		l = 1;
	if (!(sub = (char *)malloc(l)))
		return (0);
	i = 0;
	while (l > 1)
	{
		sub[i++] = s[start++];
		l--;
	}
	sub[i] = 0;
	return (sub);
}
