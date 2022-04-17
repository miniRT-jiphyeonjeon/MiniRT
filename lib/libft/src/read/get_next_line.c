/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:07:26 by cjang             #+#    #+#             */
/*   Updated: 2022/04/17 21:50:27 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

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

static t_gnl_res	free_buffer(char **buffer, t_gnl_res res)
{
	free(*buffer);
	return (res);
}

static int	read_fin(char **buffer, char **line_tmp, char **line, \
int read_num)
{
	if (read_num < 0)
		return (free_buffer(buffer, READFAIL));
	else
	{
		if (*line_tmp)
			return (free_buffer(buffer, FIN));
		*line = ft_strdup("");
		return (free_buffer(buffer, FIN));
	}
}

t_gnl_res	get_next_line(int fd, char **line)
{
	static char		*line_save[FD_MAX + 1];
	char			*buffer;
	char			*line_tmp;
	int				read_num;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0 || !line)
		return (ERROR);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	line_tmp = line_save[fd];
	if (line_save[fd])
		if (!(make_line(line, &line_save[fd], &line_tmp, NULL)))
			return (free_buffer(&buffer, ERROR));
	while (!line_save[fd])
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num <= 0)
			return (read_fin(&buffer, &line_tmp, line, read_num));
		buffer[read_num] = '\0';
		if (!(make_line(line, &line_save[fd], &line_tmp, &buffer)))
			return (free_buffer(&buffer, ERROR));
	}
	return (free_buffer(&buffer, SUCCESS));
}
