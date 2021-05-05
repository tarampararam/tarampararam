/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:32:39 by kcraster          #+#    #+#             */
/*   Updated: 2020/12/01 13:58:55 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char		*ft_strchr(const char *s, int c)
{
	char *a;

	a = (char *)s;
	while (*a != (char)c)
	{
		if (*a == '\0')
			return (0);
		a++;
	}
	return (a);
}

void		*ft_calloc(size_t count, size_t size)
{
	char		*s;
	int			i;
	int			t;

	i = 0;
	t = count * size;
	s = malloc(t);
	if (s == 0)
		return (0);
	while (t--)
		s[i++] = 0;
	return ((void *)s);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	n = i + j + 1;
	if (!(s3 = (char *)malloc(n)))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != 0)
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		s3[j++] = s2[i++];
	s3[j] = 0;
	free((char *)s1);
	return (s3);
}

char		*ft_strdup(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(a = (char *)malloc(i + 1)))
		return (0);
	i = 0;
	if (a != 0)
		while (s1[i] != '\0')
		{
			a[i] = s1[i];
			i++;
		}
	a[i] = 0;
	return (a);
}
