/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:15 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:58:58 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	input_map(char **argv, t_data *data)
{
	int		fd;
	size_t	len;

	len = ft_strlen(argv[1]);
	if (len < 4)
		ft_exit_free_line(NULL, "Invalid map_file format");
	if (ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		ft_exit_free_line(NULL, "Invalid map_file format");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_free_line(NULL, "cannot open map file");
	get_map_width_height(fd, data);
	if (data->width_field == data->height_field)
		ft_exit_free_line(NULL, "Invalid map format");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_free_line(NULL, "cannot open map file");
	is_validate_map(data, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_free_line(NULL, "cannot open map file");
	get_map_situation(data, fd);
	close(fd);
}
