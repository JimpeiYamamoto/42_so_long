/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 08:50:23 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:52:24 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_xpm_ply1(t_data *data)
{
	int	width;
	int	height;

	data->img_ply[LEFT][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_l1.xpm", &width, &height);
	data->img_ply[LEFT][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_l2.xpm", &width, &height);
	data->img_ply[LEFT][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_l3.xpm", &width, &height);
	data->img_ply[RIGHT][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_r1.xpm", &width, &height);
	data->img_ply[RIGHT][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_r2.xpm", &width, &height);
	data->img_ply[RIGHT][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_r3.xpm", &width, &height);
}

void	init_xpm_ply2(t_data *data)
{
	int	width;
	int	height;

	data->img_ply[UP][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_b1.xpm", &width, &height);
	data->img_ply[UP][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_b2.xpm", &width, &height);
	data->img_ply[UP][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_b3.xpm", &width, &height);
	data->img_ply[DOWN][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_h1.xpm", &width, &height);
	data->img_ply[DOWN][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_h2.xpm", &width, &height);
	data->img_ply[DOWN][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/ply_h3.xpm", &width, &height);
}

void	init_xpm_enm1(t_data *data)
{
	int	width;
	int	height;

	data->img_enm[LEFT][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_l1.xpm", &width, &height);
	data->img_enm[LEFT][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_l2.xpm", &width, &height);
	data->img_enm[LEFT][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_l3.xpm", &width, &height);
	data->img_enm[RIGHT][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_r1.xpm", &width, &height);
	data->img_enm[RIGHT][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_r2.xpm", &width, &height);
	data->img_enm[RIGHT][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_r3.xpm", &width, &height);
}

void	init_xpm_enm2(t_data *data)
{
	int	width;
	int	height;

	data->img_enm[UP][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_b1.xpm", &width, &height);
	data->img_enm[UP][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_b2.xpm", &width, &height);
	data->img_enm[UP][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_b2.xpm", &width, &height);
	data->img_enm[DOWN][0] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_h1.xpm", &width, &height);
	data->img_enm[DOWN][1] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_h2.xpm", &width, &height);
	data->img_enm[DOWN][2] = mlx_xpm_file_to_image(data->mlx,
			"img_bonus/enm_h3.xpm", &width, &height);
}

void	init_xpm_to_data(t_data *data)
{
	init_xpm_ply1(data);
	init_xpm_ply2(data);
	init_xpm_enm1(data);
	init_xpm_enm2(data);
	init_xpm_other1(data);
	init_xpm_other2(data);
}
