/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:20:20 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/10 17:35:54 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
