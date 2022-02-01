/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:19:54 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:44:14 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit_free_line(void *ptr, char *msg)
{
	free(ptr);
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_ptr(int **pptr, int y_len)
{
	int	y;

	y = 0;
	if (pptr == NULL)
	{
		free(pptr);
		return ;
	}
	while (y < y_len)
	{
		free(pptr[y]);
		y++;
	}
	free(pptr);
}

void	destroy_all_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		mlx_destroy_image(data->mlx, data->img_dor[i]);
		mlx_destroy_image(data->mlx, data->img_grd[i]);
		mlx_destroy_image(data->mlx, data->img_wll[i]);
		mlx_destroy_image(data->mlx, data->img_itm[i]);
		j = 0;
		while (j < 4)
		{
			mlx_destroy_image(data->mlx, data->img_ply[j][i]);
			mlx_destroy_image(data->mlx, data->img_enm[j][i]);
			j++;
		}
		i++;
	}
}

void	ft_exit(t_data *data, int status, char *msg)
{
	destroy_all_img(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->block_situ != NULL)
		free_ptr(data->block_situ, data->height_field);
	mlx_loop_end(data->mlx);
	if (status == 0)
		exit(EXIT_SUCCESS);
	else
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd(msg, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	click_red_batsu(t_data *data)
{
	ft_exit(data, EXIT_SUCCESS, NULL);
	return (0);
}
