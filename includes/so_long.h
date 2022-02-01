/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:23:23 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/27 14:21:18 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*include*/
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
/*key_code*/
# define ESC_KEY (65307)
# define W_KEY (119)
# define A_KEY (97)
# define S_KEY (115)
# define D_KEY (100)
/*map*/
typedef int	t_situ;
# define GROUND (48)
# define PLAYER (80)
# define ITEM (67)
# define WALL (49)
# define EXIT (69)
/*SQUARE*/
# define W_SQUARE (25)
# define H_SQUARE (25)
/*info*/

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_p;
	int		y_p;
	int		width_field;
	int		height_field;
	t_situ	**block_situ;
	int		move_cnt;
	int		item_cnt;
	int		player_cnt;
	int		exit_cnt;
	int		ground_cnt;
	void	*img_grd;
	void	*img_ply;
	void	*img_itm;
	void	*img_wll;
	void	*img_dor;
}				t_data;
/*init_data*/
void	init_xpm_to_data(t_data *data);
void	init_data(t_data *data);
/*input_map_utils*/
void	get_map_width_height(int fd, t_data *data);
void	is_validate_map(t_data *data, int fd);
void	receive_map(t_data *data, int x, int y, t_situ t_s);
void	get_map_situation(t_data *data, int fd);
/*error_handling*/
void	ft_exit_free_line(void *ptr, char *msg);
void	put_error_exit(void);
void	put_invalid_argument_cnt_exit(void);
void	ft_exit(t_data *data, int status, char *msg);
int		click_red_batsu(t_data *data);
/**/
void	put_console(t_data *data);
void	render_map(t_data *data);
t_bool	is_game_clear(t_data *data);
t_bool	is_enable_move(int keycode, t_data *data);
void	judge_item_get(t_data *data);

#endif
