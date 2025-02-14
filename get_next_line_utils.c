/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:41:16 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/14 23:41:16 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		ind;

	if (!str)
		return (NULL);
	ind = 0;
	dup = (char *)malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (str[ind])
	{
		dup[ind] = str[ind];
		++ind;
	}
	dup[ind] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if ((unsigned char)c == str[pos])
			return ((char *)(str + pos));
		++pos;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(str + pos));
	return (NULL);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str1 || !str2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		new_str[i] = str1[i];
		++i;
	}
	j = 0;
	while (str2[j])
	{
		new_str[i + j] = str2[j];
		++j;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	i;

	i = 0;
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
