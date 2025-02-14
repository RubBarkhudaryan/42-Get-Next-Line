/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:41:13 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/14 23:41:13 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*parse_buff(char **buffer)
{
	char	*new_line_pos;
	char	*temp;
	char	*line;

	if (!(*buffer) || !**buffer)
		return (NULL);
	new_line_pos = ft_strchr(*buffer, '\n');
	if (new_line_pos)
	{
		line = ft_substr(*buffer, 0, new_line_pos - *buffer + 1);
		temp = ft_strdup(new_line_pos + 1);
		free(*buffer);
		*buffer = temp;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static char	*read_line(int fd, char *tmp)
{
	char	temp[BUFF_SIZE + 1];
	char	*line;
	int		bytes_read;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (!ft_strchr(tmp, '\n'))
	{
		bytes_read = read(fd, temp, BUFF_SIZE);
		if (bytes_read <= 0)
		{
			if (tmp && *tmp)
				return (tmp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		line = ft_strjoin(tmp, temp);
		free(tmp);
		tmp = line;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp = NULL;

	if (fd <= 0 || BUFF_SIZE <= 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	tmp = read_line(fd, tmp);
	return (parse_buff(&tmp));
}
