/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_data2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 08:53:10 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:53:29 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_xpm_other1(t_data *data)
{
	int	width;
	int	height;

	data->img_grd[0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/grd.xpm", &width, &height);
	data->img_grd[1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/grd.xpm", &width, &height);
	data->img_grd[2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/grd.xpm", &width, &height);
	data->img_wll[0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/wll1.xpm", &width, &height);
	data->img_wll[1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/wll2.xpm", &width, &height);
	data->img_wll[2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/wll3.xpm", &width, &height);
}

void	init_xpm_other2(t_data *data)
{
	int	width;
	int	height;

	data->img_itm[0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/itm1.xpm", &width, &height);
	data->img_itm[1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/itm2.xpm", &width, &height);
	data->img_itm[2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/itm3.xpm", &width, &height);
	data->img_dor[0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/dor1.xpm", &width, &height);
	data->img_dor[1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/dor1.xpm", &width, &height);
	data->img_dor[2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/dor1.xpm", &width, &height);
}
