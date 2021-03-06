/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:58:10 by kcraster          #+#    #+#             */
/*   Updated: 2020/11/04 11:47:55 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
