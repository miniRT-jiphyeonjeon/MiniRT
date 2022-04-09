#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	tok_line(char *s, char **next)
{
	if (!s)
		return (0);
	while (*s != '\0' && *s != '\n')
		s++;
	if (*s == '\n')
	{
		*s++ = '\0';
		*next = ft_strdup(s);
		return (1);
	}
	else
	{
		*next = NULL;
		return (1);
	}
}

static int	make_line(char **line, char **line_save, char **line_tmp, \
char **buffer)
{
	if (buffer)
	{
		if (!(tok_line(*buffer, line_save)))
			return (0);
		*line = ft_strjoin(*line_tmp, *buffer);
	}
	else
	{
		if (!(tok_line(*line_save, line_save)))
			return (0);
		*line = ft_strdup(*line_tmp);
	}
	if (*line_tmp)
		free(*line_tmp);
	*line_tmp = *line;
	return (1);
}

static int	free_buffer(char **buffer, int i)
{
	free(*buffer);
	return (i);
}

static int	read_fin(char **buffer, char **line_tmp, char **line, \
int read_num)
{
	if (read_num < 0)
		return (free_buffer(buffer, -2));
	else
	{
		if (*line_tmp)
			return (free_buffer(buffer, 0));
		*line = ft_strdup("");
		return (free_buffer(buffer, 0));
	}
}

int	get_next_line(int fd, char **line)
{
	static char		*line_save[FD_MAX + 1];
	char			*buffer;
	char			*line_tmp;
	int				read_num;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	line_tmp = line_save[fd];
	if (line_save[fd])
		if (!(make_line(line, &line_save[fd], &line_tmp, NULL)))
			return (free_buffer(&buffer, -1));
	while (!line_save[fd])
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num <= 0)
			return (read_fin(&buffer, &line_tmp, line, read_num));
		buffer[read_num] = '\0';
		if (!(make_line(line, &line_save[fd], &line_tmp, &buffer)))
			return (free_buffer(&buffer, -1));
	}
	return (free_buffer(&buffer, 1));
}
