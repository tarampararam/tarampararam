/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:41:45 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/13 13:26:09 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	rev_str(char const *s1, char const *set, size_t n)
{
	size_t	j;

	j = 0;
	while (n--)
	{
		while (s1[n] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			break ;
		j = 0;
	}
	return (n);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*s2;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			break ;
		j = 0;
		i++;
	}
	n = rev_str(s1, set, ft_strlen(s1));
	s2 = ft_substr(s1, i, n - i + 1);
	return (s2);
}
