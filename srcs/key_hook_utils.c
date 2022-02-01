/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:25:35 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 09:13:40 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*select_img(int x, int y, t_data *data)
{
	int	num;

	num = data->block_situ[y][x];
	if ((x == data->x_p && y == data->y_p))
		return (data->img_ply);
	else if (num == GROUND)
		return (data->img_grd);
	else if (num == ITEM)
		return (data->img_itm);
	else if (num == EXIT)
		return (data->img_dor);
	else
		return (data->img_wll);
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

t_bool	is_game_clear(t_data *data)
{
	if (data->block_situ[data->y_p][data->x_p] == EXIT)
	{
		if (data->item_cnt == 0)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	is_enable_move(int keycode, t_data *data)
{
	int	p_x;
	int	p_y;

	p_x = data->x_p;
	p_y = data->y_p;
	if (keycode == W_KEY && data->block_situ[p_y - 1][p_x] != WALL)
		return (TRUE);
	else if (keycode == A_KEY && data->block_situ[p_y][p_x - 1] != WALL)
		return (TRUE);
	else if (keycode == S_KEY && data->block_situ[p_y + 1][p_x] != WALL)
		return (TRUE);
	else if (keycode == D_KEY && data->block_situ[p_y][p_x + 1] != WALL)
		return (TRUE);
	else
		return (FALSE);
}

void	judge_item_get(t_data *data)
{
	if (data->block_situ[data->y_p][data->x_p] == ITEM)
	{
		data->item_cnt--;
		data->block_situ[data->y_p][data->x_p] = GROUND;
	}
}
