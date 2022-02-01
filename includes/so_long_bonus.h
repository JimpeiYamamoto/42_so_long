/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:20:06 by yjimpei           #+#    #+#             */
/*   Updated: 2022/01/28 08:56:35 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*include*/
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
/*key_code*/
typedef int	t_key;
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
# define W_SQUARE (28)
# define H_SQUARE (28)
/*DIRECTION*/
typedef int	t_dire;
# define LEFT (0)
# define RIGHT (1)
# define DOWN (2)
# define UP (3)
/*FRAME_RATE*/
# define SPRITE_RATE (400)
# define ENEMY_RATE (1200)
/*PROGRAM_ALL_INFOMATION*/
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x_p;
	int		y_p;
	t_dire	p_dir;
	int		x_e;
	int		y_e;
	t_dire	e_dir;
	int		width_field;
	int		height_field;
	t_situ	**block_situ;
	int		move_cnt;
	int		item_cnt;
	int		player_cnt;
	int		exit_cnt;
	int		ground_cnt;
	void	*img_grd[3];
	void	*img_ply[4][3];
	void	*img_enm[4][3];
	void	*img_wll[3];
	void	*img_dor[3];
	void	*img_itm[3];
	int		loop_cnt;
	int		sprite_num;
}				t_data;
/*INPUT_MAP*/
void	get_map_width_height(int fd, t_data *data);
void	is_validate_map(t_data *data, int fd);
void	receive_map(t_data *data, int x, int y, t_situ t_s);
void	get_map_situation(t_data *data, int fd);
void	input_map(char **argv, t_data *data);
/*INIT_STRUCT_DATA*/
void	init_data_struct(t_data *data);
void	init_xpm_ply1(t_data *data);
void	init_xpm_ply2(t_data *data);
void	init_xpm_enm1(t_data *data);
void	init_xpm_enm2(t_data *data);
void	init_xpm_other1(t_data *data);
void	init_xpm_other2(t_data *data);
void	init_xpm_to_data(t_data *data);
/*EXIT*/
int		click_red_batsu(t_data *data);
void	ft_exit(t_data *data, int status, char *msg);
void	free_ptr(int **pptr, int y_len);
void	ft_exit_free_line(void *ptr, char *msg);
/*RENDERING*/
int		loop(t_data *data);
int		key_hook(int keycode, t_data *data);
void	render_map(t_data *data);
t_bool	is_game_finish(t_data *data);
/*ENEMY_SETTING*/
void	init_enemy_place(t_data *data);
t_bool	is_enable_move(int keycode, t_data *data, int p_x, int p_y);
void	enemy_move(t_data *data);
/*PUT_DISPLAY_STRING*/
void	put_info_bonus(t_data *data);

#endif