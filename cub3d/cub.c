/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:14:53 by kcraster          #+#    #+#             */
/*   Updated: 2021/03/10 21:08:58 by kcraster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>
#include <string.h>

void	parsing_configs(int fd, char *configs)
{
	char		*line;
	char		**line2d;
	char		*tmp = NULL;
	int			i;

	i = -1;
	line = ft_calloc(1, 1);
	line2d = ft_calloc(1, sizeof(char *));
	while (get_next_line(fd, &configs))
	{
		line = ft_strjoin(line, configs);
		line = ft_strjoin(line, "\n");
	}
	line = ft_strjoin(line, configs);
	//line2d[i] = *ft_split(line, '\n');
	//printf("%s\n", line2d[i]);
	/*while (line2d[++i])
	{
		tmp = *ft_split(line, '\n');
		line = ft_strlen(tmp) + line;
		line2d[i] = ft_strjoin(line2d[i], tmp);
		printf("%s\n", line2d[i]);
	}*/
	tmp = *ft_split(line, '\n');
	printf("tmp: %s\n", tmp);
	line = line + ft_strlen(tmp);
	printf("ost: %s\n", line);
}

int		main()
{
	int			fd;
	char		*line;

	fd = open("map.cub", O_RDONLY);
	parsing_configs(fd, line);
}
