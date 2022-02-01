/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:19:31 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:59:06 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit_free_line(NULL, "invalid number of argument");
	data.mlx = mlx_init();
	init_data_struct(&data);
	init_xpm_to_data(&data);
	input_map(argv, &data);
	init_enemy_place(&data);
	data.win = mlx_new_window(data.mlx, W_SQUARE * data.width_field,
			H_SQUARE * data.height_field, "so_long");
	mlx_loop_hook(data.mlx, loop, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, click_red_batsu, &data);
	mlx_loop(data.mlx);
	return (0);
}
