/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:19:54 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/26 03:41:47 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	while (y < y_len)
	{
		free(pptr[y]);
		y++;
	}
	free(pptr);
}

void	ft_exit(t_data *data, int status, char *msg)
{
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
