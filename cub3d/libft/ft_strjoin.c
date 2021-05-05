/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:08:39 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/07 19:44:26 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (s3);
}
