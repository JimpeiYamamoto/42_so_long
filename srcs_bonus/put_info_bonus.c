/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 07:58:45 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:29:08 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_info_bonus(t_data *data)
{
	char	*msg;
	char	*cnt;

	cnt = ft_itoa(data->move_cnt);
	msg = ft_strjoin("SCORE : ", cnt);
	mlx_string_put(data->mlx, data->win, W_SQUARE / 2,
		H_SQUARE * data->height_field - H_SQUARE / 3,
		0x00FFFFFF, msg);
	free(cnt);
	free(msg);
}
