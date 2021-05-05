/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:22:20 by kcraster          #+#    #+#             */
/*   Updated: 2021/03/02 18:00:20 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	s_parameters
{
	va_list		ap;
	int			flag_minus;
	int			flag_null;
	int			width;
	int			precision;
	int			len;
	int			nulls;
	int			spaces;
	int			dot;
	char		percent;
	char		type;
}				t_list;

int		ft_printf(const char *format, ...);
int		parsing(const char *format, t_list *pnt, int i);
int		processing(t_list *pnt);
void	int_processing(t_list *pnt, char *str, int length);
void	string_char_processing(t_list *pnt, int n, char *str, int length);
char	*ft_itoa_hex(long long unsigned n, t_list *pnt);
void	percent_processing(t_list *pnt);
void	counting_characters(t_list *pnt, int length);
void	string_processing(t_list *pnt, char *str, int length);
void	char_processing(t_list *pnt, int n, int length);

#endif
