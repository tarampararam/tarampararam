/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:44:24 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/10 17:37:19 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		count_word(char const *s, char c)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c))
			j++;
		i++;
	}
	return (j);
}

static size_t		len_word(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static void			**mem_free(char **buf)
{
	size_t i;

	i = 0;
	while (buf[i])
		free(buf[i++]);
	free(buf);
	return (0);
}

static char			*split_str(char const *s, char c, size_t i, char **buf)
{
	char	*str;
	size_t	j;
	size_t	len;

	j = 0;
	len = len_word(s, c, i);
	if (!(str = (char *)ft_calloc(len + 1, sizeof(char))))
	{
		mem_free(buf);
		return (0);
	}
	while (s[i] != c && s[i] != '\0')
		str[j++] = s[i++];
	return (str);
}

char				**ft_split(char const *s, char c)
{
	char	**buf;
	char	**str;
	size_t	i;
	size_t	cnt;

	i = 0;
	buf = NULL;
	cnt = count_word(s, c);
	if (!(str = (char **)ft_calloc(cnt + 1, sizeof(char *))))
		return (0);
	if (cnt == 0)
	{
		*str = (char *)'\0';
		return (str);
	}
	buf = str;
	while (i < ft_strlen(s) - 1)
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c))
			*str++ = split_str(s, c, ((i == 0 && s[i] != c) ? 0 : i + 1), buf);
		i++;
	}
	return (buf);
}
