/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:05:47 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 09:05:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> // for read()
//# include <fcntl.h>  // for open()

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
char	*ft_go_to_new_line(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *str);
char	*clean_up(char *str);
char	*get_line(int fd, char *str);
char	*get_next_line(int fd);
# endif
