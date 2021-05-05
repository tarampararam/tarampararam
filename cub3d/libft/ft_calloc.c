/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:15:59 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/12 14:32:11 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
