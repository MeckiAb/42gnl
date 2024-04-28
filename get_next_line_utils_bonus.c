/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:46:09 by labderra          #+#    #+#             */
/*   Updated: 2024/04/28 18:53:45 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len-- > 0)
		ptr[len] = (unsigned char)c;
	return (b);
}
