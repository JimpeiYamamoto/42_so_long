/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:43:55 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 07:05:33 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*select_img(int x, int y, t_data *data)
{
	int	num;

	num = data->block_situ[y][x];
	if ((x == data->x_p && y == data->y_p))
		return (data->img_ply[data->p_dir][data->sprite_num]);
	else if ((x == data->x_e && y == data->y_e))
		return (data->img_enm[data->e_dir][data->sprite_num % 2]);
	else if (num == GROUND)
		return (data->img_grd[data->sprite_num]);
	else if (num == ITEM)
		return (data->img_itm[data->sprite_num]);
	else if (num == EXIT)
		return (data->img_dor[data->sprite_num]);
	else
		return (data->img_wll[data->sprite_num]);
}

void	render_map(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < data->height_field)
	{
		x = 0;
		while (x < data->width_field)
		{
			img = select_img(x, y, data);
			mlx_put_image_to_window(data->mlx, data->win, img,
				W_SQUARE * x, H_SQUARE * y);
			x++;
		}
		y++;
	}
}

int	loop(t_data *data)
{
	if (data->loop_cnt == SPRITE_RATE)
	{
		render_map(data);
		data->sprite_num++;
		if (data->sprite_num == 3)
			data->sprite_num = 0;
	}
	if (data->loop_cnt == ENEMY_RATE)
	{
		enemy_move(data);
		data->loop_cnt = 0;
	}
	if (is_game_finish(data) == TRUE)
		ft_exit(data, EXIT_SUCCESS, NULL);
	data->loop_cnt++;
	return (0);
}
