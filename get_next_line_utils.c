/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabboud <cabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:12:52 by cabboud           #+#    #+#             */
/*   Updated: 2026/01/15 17:51:19 by cabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the length of a string
int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
// Returns a pointer to the first occurrence of character c in string str
char	*ft_new_line(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

// Joins two strings into a new string
char	*ft_strjoin(char *str1, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str2)
		return (free(str1), NULL);
	new = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new)
		return (NULL);
	if (str1)
	{
		while (str1[i])
		{
			new[i] = str1[i];
			i++;
		}
	}
	while (str2[j])
		new[i++] = str2[j++];
	new[i] = '\0';
	free(str1);
	return (new);
}

// Extracts a substring from the beginning of str up to and including the first newline
char	*ft_substr(char	*str)
{
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = malloc(i * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = '\0';
	return (new_str);
}