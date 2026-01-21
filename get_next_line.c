/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:05:53 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 09:05:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Extracts a substring from the beginning of str up to and including the first newline
char	*clean_up(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	i++;
	new_str = malloc(ft_strlen(str + i) * sizeof(char) + 1);
	if (!new_str)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

// Reads from the file descriptor until a newline is found or end of file is reached
char	*get_line(int fd, char *str)
{
	char	*row;
	int		c_read;

	row = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!row)
		return (free(str), NULL);
	c_read = 1;
	while (!ft_go_to_new_line(str, '\n') && c_read > 0)
	{
		c_read = read(fd, row, BUFFER_SIZE);
		if (c_read == 0)
			break;
		if (c_read < 0)
			return (free(row), free(str), NULL);
		row[c_read] = '\0';
		str = ft_strjoin(str, row);
		if (!str)
			return (free(row), NULL);
	}
	free(row);
	return (str);
}

// Retrieves the next line from the file descriptor
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_line(fd, stash);
	if (!stash || stash[0] == '\0')
    	return (free(stash), stash = NULL, NULL);
	line = ft_substr(stash);
	stash = clean_up(stash);
	return (line);
}
