/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:00:25 by rbarkhud          #+#    #+#             */
/*   Updated: 2025/02/13 18:48:59 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

struct	vector_
{
	char	*str;
	int		size;
	int		capacity;

} vector;

vector	__constructor__();
void	push_back(vector &vct, char c);
void	resize(vector &vct, int new_size);
void	reserve(vector &vct, int capacity);

#endif