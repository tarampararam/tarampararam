/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:46:33 by kcraster          #+#    #+#             */
/*   Updated: 2021/03/08 14:04:03 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	check_errors(char **rest, char **buf, char **line, int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (0);
	if (!*rest)
		*rest = ft_calloc(1, 1);
	if (!(*buf = (char *)malloc(sizeof(char) *
					(BUFFER_SIZE + 1))) && !*rest)
		return (0);
	return (1);
}

static int	nothing_to_read(int cnt, char **rest)
{
	if (cnt == 0 && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (0);
}

static int	rip(char **rest, char **pn, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (*rest)
	{
		if ((*pn = ft_strchr(*rest, '\n')))
		{
			**pn = '\0';
			*line = ft_strdup(*rest);
			tmp = *rest;
			*rest = ft_strdup((*pn + 1));
			free(tmp);
			return (1);
		}
		else
			*line = ft_strdup(*rest);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	char		*pn;
	static char	*rest;
	int			cnt;

	if (!check_errors(&rest, &buf, line, fd))
		return (-1);
	while (!((pn = ft_strchr(rest, '\n'))) &&
		((cnt = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[cnt] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	if (cnt < 0)
		return (-1);
	free(buf);
	if (rip(&rest, &pn, line))
		return (1);
	if (!nothing_to_read(cnt, &rest))
		return (0);
	return (1);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	while (get_next_line(fd, &line))
		printf("%s\n", line);
}