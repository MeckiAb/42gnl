/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:49:32 by labderra          #+#    #+#             */
/*   Updated: 2024/04/29 00:41:20 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (-2);
	else if (bytes_read <= 0)
		return (-1);
	else
		return (my_buffer[bytes_read] = 0, 0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	int			i;
	char		*result;
	int			j;
	int			size;

	result = init_result(fd, &size, &i, &j);
	while (buffer[i] != '\n')
	{
		if (!result || i < 0)
			return (buffer[0] = 0, free (result), NULL);
		while (buffer[i] != '\n' && j < size && buffer[i])
			result[j++] = buffer[i++];
		if (j >= size)
			result = resize_buffer(&result, &size, BUFFER_SIZE);
		else if (!buffer[i])
		{
			i = file_read(fd, buffer, j);
			if (i == -2)
				return (buffer[0] = 0, result);
		}
	}
	ft_memmove(&buffer[0], &buffer[i + 1], BUFFER_SIZE - i);
	return (result[j] = '\n', resize_buffer(&result, &size, 1));
}
