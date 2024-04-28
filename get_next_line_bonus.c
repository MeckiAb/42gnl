/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:49:32 by labderra          #+#    #+#             */
/*   Updated: 2024/04/28 19:04:27 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[FD_SETSIZE][BUFFER_SIZE + 1] = {0};
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
		while (buffer[fd][i] != '\n' && j < size && buffer[fd][i])
		{
			result[j++] = buffer[fd][i++];
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
		else if (!buffer[fd][i])
		{
			i = read(fd, buffer[fd], BUFFER_SIZE);
			if (i < 0 || (i == 0 && j == 0))
			{
				buffer[fd][0] = '\0';
				free(result);
				return (NULL);
			}			
			else if ( i == 0 && j != 0)
			{
				buffer[fd][0] = '\0';
				result[j] = '\0';
				return (result);
			}
			buffer[fd][i] = '\0';
			i = 0;
		}
		else if (buffer[fd][i] == '\n')
		{
			ft_memmove(&buffer[fd][0], &buffer[fd][i + 1], BUFFER_SIZE - i);
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
