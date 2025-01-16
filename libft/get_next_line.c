/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:25:23 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 16:25:48 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*checkfree(char *buff, char *buffer)
{
	if (buff)
		free(buff);
	if (buffer)
		free(buffer);
	return (NULL);
}

static char	*readbuff(char *buff, char *buffer, int fd)
{
	ssize_t	bytes;
	char	*temp;

	while (!g_ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (checkfree(buff, buffer));
		else if (bytes == 0 && *buffer == '\0')
			return (checkfree(buff, buffer));
		if (bytes == 0)
			break ;
		buff[bytes] = '\0';
		temp = ft_strjoin(buffer, buff);
		if (!temp)
			return (checkfree(buff, buffer));
		free(buffer);
		buffer = temp;
	}
	free(buff);
	return (buffer);
}

static char	*splitline(char *buffer)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	if (buffer[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		line[j++] = buffer[i++];
	if (buffer[i] == '\n')
		line[j++] = buffer[i];
	line[j] = '\0';
	return (line);
}

static char	*ft_save(char *buffer)
{
	char	*new;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	new = g_ft_strdup(buffer, i);
	if (!new)
		return (NULL);
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (checkfree(NULL, buffer));
	buffer = readbuff(buff, buffer, fd);
	if (!buffer)
		return (NULL);
	line = splitline(buffer);
	if (!line)
		return (checkfree(buff, NULL));
	buffer = ft_save(buffer);
	if (!buffer)
		(checkfree(NULL, buffer));
	return (line);
}

// int main(void)
// {
//     int fd = open("te.txt", O_RDONLY);
//     char *line;
//     while (line = get_next_line(fd))
//     {
//         printf("%s", line);
//         free(line);
//     }

// }