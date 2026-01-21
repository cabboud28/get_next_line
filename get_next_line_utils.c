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
// when it finds \n for example, it goes to a new line
char	*ft_go_to_new_line(char *str, int c)
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
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (free(s1), NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

// Extracts a substring from the beginning of str up to and including the first newline
char	*ft_substr(char	*str)
{
	int		i;
	char	*sub_str;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	sub_str = malloc(i * sizeof(char) + 1);
	if (!sub_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		sub_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		sub_str[i++] = '\n';
	sub_str[i] = '\0';
	return (sub_str);
}
