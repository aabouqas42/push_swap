/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:27:01 by aabouqas          #+#    #+#             */
/*   Updated: 2023/12/02 11:36:59 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(char *line, char **rem_ltrs)
{
	char	*new_line;
	int		len;
	int		i;

	len = 0;
	if (!line || !*line)
		return (free (line), free (*rem_ltrs), *rem_ltrs = NULL, NULL);
	if (!found_newline(line))
		return (line);
	while (line[len] && line[len] != '\n')
		len++;
	len++;
	new_line = malloc (len + 1);
	if (!new_line)
		return (free (line), free (*rem_ltrs), *rem_ltrs = NULL, NULL);
	i = 0;
	while (line[i] && i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (free (line), new_line);
}

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*buffer;
	char		*line;
	ssize_t		readed;

	readed = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free (rem), rem = NULL, NULL);
	buffer = malloc ((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free (rem), rem = NULL, NULL);
	line = app_end(rem, line);
	while (!found_newline(line) && readed)
	{
		readed = read (fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free (line), free (buffer), free (rem), rem = NULL, NULL);
		buffer[readed] = '\0';
		line = app_end(line, buffer);
	}
	rem = get_remaining_laters(line);
	free (buffer);
	return (get_the_line(line, &rem));
}
