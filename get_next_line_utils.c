/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:00:29 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/13 18:54:57 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

vector	__constructor__()
{
	vector	vct;
	int		i;

	i = 0;
	vct.size = BUFFER_SIZE + 1;
	vct.capacity = 2;
	vct.str = (char *)malloc(vct.size);
	if (!vct.str)
		vct.str = NULL;
	while (i < vct.size)
	{
		vct.str[i] = '';
		++i;
	}
	return (vct);
}

void	push_back(vector &vct, char c)
{
	if (vct.size + 1 >= vct.capacity)
		reserve(vct, vct.size + 1);
	vct.str[vct.size++] = c;
	vct.str[vct.size] = '\0';
}

void	reserve(vector &vct, int size)
{
	
}

void	resize(vector &vct, int size)