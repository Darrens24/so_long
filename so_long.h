/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:26:40 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/17 13:24:38 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ANIM_FRAME 50

# include "libft.h"
# include <mlx.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_window
{
	void	*addr;
	t_point	size;
}				t_window;

typedef struct s_map
{
	char	**map;
	char	*name;
	int		len;
	int		hei;
	int		nb_exit;
	int		nb_play;
	int		nb_col;
	t_point	pos_play;
	t_point	pos_exit;
}				t_map;				

typedef struct s_image
{
	t_map		map;
	void		*mlx;
	void		*img;
	void		*floor;
	void		*tree;
	void		*peng;
	void		*hole;
	void		*igloo;
	void		*sushi;
	void		*snow;
	void		*addr;
	t_window	window;
	int			bpp;
	int			line_len;
	int			endian;
	int			img_w;
	int			img_h;
	int			mov_count;
	char		*msg_mov;
	t_point		spr_pos;
}				t_image;

//Map Data
t_map	get_map(char *arg);
void	get_items(t_map *map, int i, int j);
void	free_path(char **path);
void	free_all(t_image *im);

//Pathfinding
char	**allocate_path(t_map map);
int		check_path(char **path, int i, int j, t_map map);
int		path_is_ok(char **path);

//Errors
int		check_form(t_map map);
int		check_walls(t_map map);
int		check_items(t_map *map, int i, int j);
int		no_map_errors(t_map map, char **path);

//MLX Image
t_image	get_data_img(t_image *im);
void	get_floor(t_image *im);
void	get_tree(t_image *im);
void	get_hole(t_image *im);
void	get_igloo(t_image *im);
void	get_peng(t_image *im);
void	get_sushi(t_image *im);
void	get_snow(t_image *im);
void	put_floor(t_image *img);
void	put_floor2(t_image *img);
void	put_walls(t_image *img);
void	put_tree(t_image *img);
void	put_player(t_image *img);
void	put_exit(t_image *img);
void	put_col(t_image *img);
void	put_enemy(t_image *img);
void	put_game(t_image *im);

//MLX Hooks
int		close_win(t_image *im);
int		input(int keycode, void *param);
int		input2(int keycode, void *param);
int		input3(int keycode, void *param);
int		input4(int keycode, void *param);
char	*conv_mv(t_image *i);

//Animations
void	put_snow(t_image *img);
int		update_frame(void *param);

#endif