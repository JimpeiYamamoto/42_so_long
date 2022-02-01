/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:15:51 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 05:23:50 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_map_width_height(int fd, t_data *data)
{
	char	*line;
	int		r;

	r = get_next_line(fd, &line);
	if (r == -1)
		ft_exit_free_line(line, "Invalid map format");
	data->height_field += 1;
	data->width_field += ft_strlen(line);
	free(line);
	while (r == 1)
	{
		r = get_next_line(fd, &line);
		if (data->width_field != (int)ft_strlen(line))
			ft_exit_free_line(line, "Invalid map format");
		data->height_field++;
		free(line);
	}
}

static t_bool	is_validate_line(char *line, t_data *data, int x, int y)
{
	int	tmp;

	tmp = (int)line[x];
	if (tmp != WALL && (x == 0 || y == 0 || x == data->width_field - 1
			|| y == data->height_field - 1))
		return (FALSE);
	else if (tmp == PLAYER)
		data->player_cnt++;
	else if (tmp == ITEM)
		data->item_cnt++;
	else if (tmp == EXIT)
		data->exit_cnt++;
	else if (tmp == GROUND)
		data->ground_cnt++;
	else if (tmp != WALL)
		return (FALSE);
	return (TRUE);
}

void	is_validate_map(t_data *data, int fd)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (y < data->height_field)
	{
		x = 0;
		get_next_line(fd, &line);
		while (x < data->width_field)
		{
			if (is_validate_line(line, data, x, y) != TRUE)
				ft_exit_free_line(line, "invalid map format");
			x++;
		}
		free(line);
		y++;
	}
	if (data->player_cnt != 1 || data->item_cnt == 0 || data->exit_cnt != 1
		|| data->ground_cnt == 0)
		ft_exit_free_line(NULL, "invalid map format");
}

void	receive_map(t_data *data, int x, int y, t_situ t_s)
{
	data->block_situ[y][x] = t_s;
	if (data->block_situ[y][x] == PLAYER)
	{
		data->x_p = x;
		data->y_p = y;
		data->block_situ[y][x] = GROUND;
	}
}

void	get_map_situation(t_data *data, int fd)
{
	int		x;
	int		y;
	char	*line;

	data->block_situ = malloc(sizeof(int *) * data->height_field);
	if (data->block_situ == NULL)
		ft_exit_free_line(NULL, "cannot alocate memory");
	y = 0;
	while (y < data->height_field)
	{
		data->block_situ[y] = malloc(sizeof(int) * data->width_field);
		if (data->block_situ[y] == NULL)
			ft_exit(data, EXIT_FAILURE, "cannot alocate memory");
		get_next_line(fd, &line);
		x = 0;
		while (x < data->width_field)
		{
			receive_map(data, x, y, (t_situ)line[x]);
			x++;
		}
		y++;
		free(line);
	}
}
