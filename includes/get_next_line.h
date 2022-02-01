/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:22:10 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/27 14:22:29 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define MAX_FD 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

size_t	ft_strlen2(const char *s);
size_t	ft_strlcpy2(char *dest, char *src, size_t dst_size);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup2(const char *s);
int		get_next_line(int fd, char **line);

#endif
