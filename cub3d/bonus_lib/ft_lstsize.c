/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:59:19 by kcraster          #+#    #+#             */
/*   Updated: 2021/03/10 19:16:37 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int		ft_lstsize(t_list *lst)
{
	int			len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
