/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:55:55 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/09 13:03:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	gnl_reduce(char *buffer, char *storage)
{
	int		index;
	int		stg_index;

	index = 1;
	while (buffer[index] && buffer[index - 1] != '\n')
		index++;
	stg_index = 0;
	while (buffer[index])
		storage[stg_index++] = buffer[index++];
	storage[stg_index] = 0;
}

static char	*gnl_line(char *buffer)
{
	char	*value;
	int		index;

	index = 1;
	while (buffer[index] && buffer[index - 1] != '\n')
		index++;
	value = ft_calloc(index + 1, sizeof(char));
	if (!value)
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		value[index] = buffer[index];
		index++;
	}
	if (buffer[index] && buffer[index] == '\n')
		value[index] = '\n';
	return (value);
}

static char	*gnl_read(int fd, char *storage)
{
	char	*value;
	char	buffer[BUFFER_SIZE + 1];
	int		byte_read;

	value = ft_strdup(storage);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(value);
			return (NULL);
		}
		buffer[byte_read] = 0;
		value = ft_freejoin(value, buffer);
		if (!value)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			return (value);
	}
	return (value);
}

char	*get_next_line(int fd)
{
	static char	buffer[__FD_SETSIZE][BUFFER_SIZE];
	char		*read;
	char		*value;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read = gnl_read(fd, buffer[fd]);
	if (!read)
		return (0);
	if (!read[0])
	{
		free(read);
		return (NULL);
	}
	value = gnl_line(read);
	gnl_reduce(read, buffer[fd]);
	free(read);
	return (value);
}
