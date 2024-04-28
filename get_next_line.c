/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:49:32 by labderra          #+#    #+#             */
/*   Updated: 2024/04/28 13:50:41 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	int			i;
	char		*result;
	int			j;
	char		*aux;
	int			size;

	if (fd < 0)
		return (NULL);
	i = 0;
	j = 0;
	size = BUFFER_SIZE + 1;
	result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!result)
		return (NULL);
	result = ft_memset(result, 0, BUFFER_SIZE + 1);
	while (1)
	{
		while (buffer[i] != '\n' && j < size && buffer[i])
		{
			result[j++] = buffer[i++];
		}
		if (j >= size)
		{
			aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + j));
			if (!aux)
				return (NULL);
			size = size + BUFFER_SIZE;
			aux = ft_memset(aux, 0, BUFFER_SIZE + j);
			aux = ft_memmove(aux, result, j);
			free(result);
			result = aux;
		}
		else if (!buffer[i])
		{
			i = read(fd, buffer, BUFFER_SIZE);
			if (i < 0 || (i == 0 && j == 0))
			{
				buffer[0] = '\0';
				free(result);
				return (NULL);
			}			
			else if ( i == 0 && j != 0)
			{
				buffer[0] = '\0';
				result[j] = '\0';
				return (result);
			}
			buffer[i] = '\0';
			i = 0;
		}
		else if (buffer[i] == '\n')
		{
			ft_memmove(&buffer[0], &buffer[i + 1], BUFFER_SIZE - i);
			result[j++] = '\n';
			if (j < size)
				result[j++] = '\0';
			else
			{
				aux = (char *)malloc(sizeof(char) * (1 + j));
				if (!aux)
					return (NULL);
				size = size + 1;
				aux = ft_memset(aux, 0, 1 + j);
				aux = ft_memmove(aux, result, j);
				free(result);
				result = aux;
				result[j] = 0;
			}
			return (result);
		}
	}
}
