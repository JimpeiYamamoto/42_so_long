/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:35:01 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/27 07:49:28 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm_to_data(t_data *data)
{
	int	width;
	int	height;

	data->img_grd = mlx_xpm_file_to_image(data->mlx,
			"img/ground.xpm", &width, &height);
	data->img_itm = mlx_xpm_file_to_image(data->mlx,
			"img/item.xpm", &width, &height);
	data->img_ply = mlx_xpm_file_to_image(data->mlx,
			"img/chara.xpm", &width, &height);
	data->img_wll = mlx_xpm_file_to_image(data->mlx,
			"img/wall.xpm", &width, &height);
	data->img_dor = mlx_xpm_file_to_image(data->mlx,
			"img/door.xpm", &width, &height);
}

void	init_data(t_data *data)
{
	data->x_p = -1;
	data->y_p = -1;
	data->width_field = 0;
	data->height_field = 0;
	data->move_cnt = 0;
	data->item_cnt = 0;
	data->player_cnt = 0;
	data->exit_cnt = 0;
	data->ground_cnt = 0;
	init_xpm_to_data(data);
}
