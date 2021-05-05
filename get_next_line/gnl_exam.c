#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

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

size_t		ft_strlen(char *s)
{
	int		i;
	
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
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
	free((char *)s1);
	return (s3);
}
int			get_next_line(int fd, char **line)
{
	char		*buf;
	char		*pn;
	int			cnt;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_calloc(1, 1);
	buf = malloc(1);
	while (!((pn = ft_strchr(*line, '\n'))) &&
		((cnt = read(fd, buf, 1)) > 0))
	{
		buf[cnt] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
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
