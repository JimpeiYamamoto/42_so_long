/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_setting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:09:14 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:58:09 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_enemy_place(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height_field)
	{
		x = 0;
		while (x < data->width_field)
		{
			if (data->block_situ[y][x] == GROUND
				&& !(x == data->x_p && y == data->y_p))
			{
				data->x_e = x;
				data->y_e = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	calc_distanse(int x1, int y1, int x2, int y2)
{
	int	dis;
	int	tmp;

	tmp = x1 - x2;
	if (tmp < 0)
		tmp *= -1;
	dis = tmp;
	tmp = y1 - y2;
	if (tmp < 0)
		tmp *= -1;
	dis += tmp;
	return (dis);
}

void	adjust_key_dire(t_key key, int *x_move, int *y_move, t_dire *direction)
{
	*y_move = 0;
	*x_move = 0;
	if (key == W_KEY)
	{
		*y_move = -1;
		*direction = UP;
	}
	else if (key == A_KEY)
	{
		*x_move = -1;
		*direction = LEFT;
	}
	else if (key == S_KEY)
	{
		*y_move = 1;
		*direction = DOWN;
	}
	else if (key == D_KEY)
	{
		*x_move = 1;
		*direction = RIGHT;
	}
}

int	select_direction(t_key key, t_data *data, int len)
{
	int		tmp;
	int		x_move;
	int		y_move;
	t_dire	direction;

	adjust_key_dire(key, &x_move, &y_move, &direction);
	if (is_enable_move(key, data, data->x_e, data->y_e) == TRUE)
	{
		tmp = calc_distanse(data->x_p, data->y_p,
				data->x_e + x_move, data->y_e + y_move);
		if (tmp < len)
		{
			len = tmp;
			data->e_dir = direction;
		}
	}
	return (len);
}

void	enemy_move(t_data *data)
{
	int	len;

	len = data->width_field + data->height_field;
	len = select_direction(W_KEY, data, len);
	len = select_direction(A_KEY, data, len);
	len = select_direction(S_KEY, data, len);
	len = select_direction(D_KEY, data, len);
	if (data->e_dir == UP)
		data->y_e--;
	else if (data->e_dir == DOWN)
		data->y_e++;
	else if (data->e_dir == RIGHT)
		data->x_e++;
	else if (data->e_dir == LEFT)
		data->x_e--;
}
