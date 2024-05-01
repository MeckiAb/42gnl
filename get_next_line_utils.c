/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:46:09 by labderra          #+#    #+#             */
/*   Updated: 2024/05/01 01:50:17 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	ptr = (char *)dst;
	while (src <= dst && len--)
		ptr[len] = ((char *)src)[len];
	while (src > dst && i < len)
	{
		ptr[i] = ((char *)src)[i];
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = count * size;
	p = malloc(i);
	if (!p)
		return (NULL);
	while (i-- > 0)
		p[i] = 0;
	return ((void *)p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
