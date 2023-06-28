/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:37:08 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/27 21:02:39 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr2(char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);

char	*extract_newline(char *save);
char	*after_newline_save(char *save);
char	*read_and_save(int fd, char *save);
char	*get_next_line(int fd);

#endif
