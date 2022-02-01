/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:53:06 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/27 14:21:39 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_eol(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_free2(char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

static int	ft_line_trim(char **stock, char **line, int fd)
{
	ssize_t	count;
	char	*str;

	count = check_eol(stock[fd]);
	*(stock[fd] + count) = '\0';
	*line = ft_strdup2(stock[fd]);
	str = ft_strdup2(stock[fd] + count + 1);
	ft_free2(stock[fd]);
	stock[fd] = str;
	return (1);
}

static int	ft_check(char **stock, char **line, ssize_t r, int fd)
{
	int	count;

	if (r < 0)
		return (-1);
	count = check_eol(stock[fd]);
	if (stock[fd] && count >= 0)
		return (ft_line_trim(stock, line, fd));
	else if (stock[fd])
	{
		*line = stock[fd];
		stock[fd] = NULL;
		return (0);
	}
	*line = ft_strdup2("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock[MAX_FD];
	char		*tmp;
	ssize_t		r;
	ssize_t		count;

	if (fd > MAX_FD || !line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = read(fd, tmp, BUFFER_SIZE);
	while (r > 0)
	{
		tmp[r] = '\0';
		stock[fd] = ft_strjoin2(stock[fd], tmp);
		count = check_eol(stock[fd]);
		if (count >= 0)
		{
			ft_free2(tmp);
			return (ft_line_trim(stock, line, fd));
		}
		r = read(fd, tmp, BUFFER_SIZE);
	}
	ft_free2(tmp);
	return (ft_check(stock, line, r, fd));
}
