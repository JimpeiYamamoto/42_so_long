/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_console.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:18:21 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/27 08:18:49 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_console(t_data *data)
{
	ft_printf("\e[2J");
	ft_printf("total_move_cnt:%d\n", data->move_cnt);
	ft_printf("need__item_cnt:%d\n", data->item_cnt);
}
