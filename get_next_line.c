/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:49:32 by labderra          #+#    #+#             */
/*   Updated: 2024/04/27 17:44:11 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
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
	result[BUFFER_SIZE] = 0;
	while (1)
	{
		while (buffer[i] && buffer[i] != '\n' && j < size)
		{
			result[j++] = buffer[i++];
		}
		if (buffer[i] == '\n')
		{
			ft_memmove(&buffer[0], &buffer[i + 1], BUFFER_SIZE - i);
			result[j++] = '\n';
			result[j++] = '\0';
			return (result);
		}
		else if (!buffer[i])
		{
			i = read(fd, buffer, BUFFER_SIZE);
			printf("\nnew buffer - buf=%s res=%s size=%d j=%d\n", buffer, result, size, j);
			if (i <= 0 && j == 0)
			{
				buffer[0] = '\0';
				free(result);
				return (NULL);
			}
			else if ( i <= 0 && j != 0)
			{
				buffer[0] = '\0';
				result[j] = '\0';
				return (result);
			}
			buffer[i] = '\0';
			i = 0;
		}
		else if (j == size)
		{
			aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1 + j));
			if (!aux)
				return (NULL);
			size = size + BUFFER_SIZE;
			ft_strlcpy(aux, result, BUFFER_SIZE + 1 + j);
			free(result);
			result = aux;
		}
	}
}
