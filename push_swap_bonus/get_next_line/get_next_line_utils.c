/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:28:41 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/12 16:05:05 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	string_len(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL || *str == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*app_end(char *str1, char *str2)
{
	char	*str;
	int		len;
	int		i;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	len = string_len(str1) + string_len(str2);
	str = malloc (len + 1);
	if (str == NULL)
		return (free (str1), NULL);
	i = 0;
	if (str1)
	{
		while (str1[i])
		{
			str[i] = str1[i];
			i++;
		}
	}
	if (str2)
		while (*str2)
			str[i++] = *(str2++);
	str[i] = '\0';
	return (free (str1), str);
}

int	found_newline(char	*line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_remaining_laters(char	*str)
{
	char	*remaining_laters;
	int		len;
	int		i;

	if (!found_newline(str) || !str)
		return (NULL);
	while (*str && *str != '\n')
		str++;
	str++;
	if (!*str)
		return (NULL);
	len = string_len(str);
	remaining_laters = malloc (len + 1);
	if (!remaining_laters)
		return (NULL);
	i = 0;
	while (str[i])
	{
		remaining_laters[i] = str[i];
		i++;
	}
	remaining_laters[i] = '\0';
	return (remaining_laters);
}
