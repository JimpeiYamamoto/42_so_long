/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:35:01 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:56:27 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_data_struct(t_data *data)
{
	data->x_p = -1;
	data->y_p = -1;
	data->p_dir = DOWN;
	data->x_e = -1;
	data->y_e = -1;
	data->e_dir = DOWN;
	data->width_field = 0;
	data->height_field = 0;
	data->move_cnt = 0;
	data->item_cnt = 0;
	data->player_cnt = 0;
	data->exit_cnt = 0;
	data->ground_cnt = 0;
	data->loop_cnt = SPRITE_RATE;
	data->sprite_num = 0;
}
