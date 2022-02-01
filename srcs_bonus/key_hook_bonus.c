/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:48:18 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:59:30 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_bool	is_game_finish(t_data *data)
{
	if (data->block_situ[data->y_p][data->x_p] == EXIT)
	{
		if (data->item_cnt == 0)
			return (TRUE);
	}
	else if (data->x_p == data->x_e && data->y_p == data->y_e)
		return (TRUE);
	return (FALSE);
}

t_bool	is_enable_move(int keycode, t_data *data, int p_x, int p_y)
{
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

static void	judge_item_get(t_data *data)
{
	if (data->block_situ[data->y_p][data->x_p] == ITEM)
	{
		data->item_cnt--;
		data->block_situ[data->y_p][data->x_p] = GROUND;
	}
}

static t_dire	change_direction_ply(t_data *data, int keycode)
{
	if (keycode == W_KEY)
		return (UP);
	else if (keycode == A_KEY)
		return (LEFT);
	else if (keycode == S_KEY)
		return (DOWN);
	else if (keycode == D_KEY)
		return (RIGHT);
	else
		return (data->p_dir);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		ft_exit(data, EXIT_SUCCESS, NULL);
	data->p_dir = change_direction_ply(data, keycode);
	if (is_enable_move(keycode, data, data->x_p, data->y_p) == TRUE)
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
		render_map(data);
		put_info_bonus(data);
		if (is_game_finish(data) == TRUE)
			ft_exit(data, EXIT_SUCCESS, NULL);
	}
	return (0);
}
