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

static char	*parse_buff(char** clean_line, char *tmp)
{
	char	*new_line_pos;
	char	*temp;

	new_line_pos = ft_strchr(tmp, '\n');
	if (new_line_pos)
	{
		if (*clean_line)
			*clean_line = ft_strjoin(*clean_line, ft_substr(tmp, 0, new_line_pos - tmp + 1));
		else
		{
			*clean_line = ft_substr(tmp, 0, new_line_pos - tmp + 1);
			printf("%s\n", *clean_line);
		}
		temp = ft_strdup(new_line_pos + 1);
		free(tmp);
		tmp = temp;
	}
	else
	{
		*clean_line = ft_strjoin(*clean_line, tmp);
		free(tmp);
		tmp = NULL;
	}
	return (tmp);
}

static char	*read_line(int fd, char *tmp)
{
	char	*buff;
	int		size;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	size = 1;
	while (size > 0 && !ft_strchr(buff, '\n'))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == 0)
		{
			free(buff);
			return (tmp);
		}
		if (size < 0)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	free(buff);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = read_line(fd, tmp);
	if (!tmp)
		return (NULL);
	tmp = parse_buff(&line, tmp);
	return (line);
}
