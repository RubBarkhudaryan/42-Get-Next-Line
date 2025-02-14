/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:35:44 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/14 18:35:44 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_from_file(int fd, char **tmp, char *buff)
{
	int		bytes_read;
	char	*temp;

	bytes_read = read(fd, buff, BUFF_SIZE);
	if (bytes_read < 0)
		return (-1);
	buff[bytes_read] = '\0';
	temp = ft_strjoin(*tmp, buff);
	free(*tmp);
	*tmp = temp;
	return (bytes_read);
}

static char	*extract_line(char **tmp)
{
	char	*newline_pos;
	char	*line;
	char	*temp;

	newline_pos = ft_strchr(*tmp, '\n');
	if (newline_pos)
	{
		line = ft_substr(*tmp, 0, newline_pos - *tmp);
		temp = ft_strdup(newline_pos + 1);
		free(*tmp);
		*tmp = temp;
	}
	else
	{
		line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
	}
	return (line);
}

char	*read_line(int fd, char **tmp)
{
	char	*buff;
	int		bytes_read;
	char	*newline_pos;

	buff = (char *)malloc(BUFF_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	newline_pos = ft_strchr(*tmp, '\n');
	while (!(newline_pos) && bytes_read > 0)
	{
		bytes_read = read_from_file(fd, tmp, buff);
		if (bytes_read < 0)
		{
			free(buff);
			return (NULL);
		}
		newline_pos = ft_strchr(*tmp, '\n');
	}
	free(buff);
	if (bytes_read <= 0 && !*tmp)
		return (NULL);
	return (extract_line(tmp));
}

char	*get_next_line(int fd)
{
	static char	*tmp = NULL;
	char		*line;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	line = read_line(fd, &tmp);
	if (!line)
	{
		free(tmp);
		tmp = NULL;
	}
	return (line);
}
