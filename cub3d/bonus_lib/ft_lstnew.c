/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:55:32 by kcraster          #+#    #+#             */
/*   Updated: 2021/03/10 19:13:16 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_list			*ft_lstnew(void *content)
{
	t_list		*pnt;

	if (!(pnt = (t_list *)malloc(sizeof(pnt))))
		return (NULL);
	pnt->content = content;
	pnt->next = NULL;
	return (pnt);
}
