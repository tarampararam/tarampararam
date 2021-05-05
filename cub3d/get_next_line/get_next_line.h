/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:29:06 by kcraster          #+#    #+#             */
/*   Updated: 2021/03/09 19:32:58 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
int			get_next_line(int fd, char **line);
#endif
