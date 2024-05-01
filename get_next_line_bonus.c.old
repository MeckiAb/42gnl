/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:49:32 by labderra          #+#    #+#             */
/*   Updated: 2024/04/29 00:54:21 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*init_result(int fd, int *size, int *i, int *j)
{
	char	*result;

	*i = 0;
	*j = 0;
	*size = BUFFER_SIZE + 1;
	if (fd < 0)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!result)
		return (NULL);
	result = ft_memset(result, 0, BUFFER_SIZE + 1);
	return (result);
}

static char	*resize_buffer(char **result, int *size, int increment)
{
	char	*aux;

	aux = (char *)malloc(sizeof(char) * (increment + *size));
	if (!aux)
		return (NULL);
	aux = ft_memset(aux, 0, increment + *size);
	aux = ft_memmove(aux, *result, *size);
	*size = *size + increment;
	free(*result);
	return (aux);
}

static int	file_read(int fd, void *buffer, int j)
{
	int		bytes_read;
	char	*my_buffer;

	my_buffer = (char *)buffer;
	bytes_read = read(fd, my_buffer, BUFFER_SIZE);
	if (bytes_read == 0 && j != 0)
		return (my_buffer[0] = 0, -2);
	else if (bytes_read <= 0)
		return (my_buffer[0] = 0, -1);
	else
		return (my_buffer[bytes_read] = 0, 0);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_SETSIZE][BUFFER_SIZE + 1] = {0};
	int			i;
	char		*result;
	int			j;
	int			size;

	result = init_result(fd, &size, &i, &j);
	while (buffer[fd][i] != '\n')
	{
		if (!result || i < 0)
			return (free (result), NULL);
		while (buffer[fd][i] != '\n' && j < size && buffer[fd][i])
			result[j++] = buffer[fd][i++];
		if (j >= size)
			result = resize_buffer(&result, &size, BUFFER_SIZE);
		else if (!buffer[fd][i])
		{
			i = file_read(fd, buffer[fd], j);
			if (i == -2)
				return (result);
		}
	}
	ft_memmove(&buffer[fd][0], &buffer[fd][i + 1], BUFFER_SIZE - i);
	return (result[j] = '\n', resize_buffer(&result, &size, 1));
}
