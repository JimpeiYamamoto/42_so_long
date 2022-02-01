/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:21:45 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/27 14:07:01 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		ft_exit(data, EXIT_SUCCESS, NULL);
	if (is_enable_move(keycode, data) == TRUE)
	{
		if (keycode == W_KEY)
			data->y_p -= 1;
		else if (keycode == A_KEY)
			data->x_p -= 1;
		else if (keycode == S_KEY)
			data->y_p += 1;
		else if (keycode == D_KEY)
			data->x_p += 1;
		data->move_cnt++;
		judge_item_get(data);
		put_console(data);
		render_map(data);
		if (is_game_clear(data) == TRUE)
			ft_exit(data, EXIT_SUCCESS, NULL);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit_free_line(NULL, "invalid number of argument");
	data.mlx = mlx_init();
	init_data(&data);
	input_map(argv, &data);
	data.win = mlx_new_window(data.mlx, W_SQUARE * data.width_field,
			H_SQUARE * data.height_field, "so_long");
	render_map(&data);
	mlx_hook(data.win, 17, 1L << 17, click_red_batsu, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
