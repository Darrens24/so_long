/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:56:46 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/17 13:39:24 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	get_data_img(t_image *im)
{
	im->window.size.x = im->map.len * 64;
	im->window.size.y = im->map.hei * 64;
	im->window.addr = mlx_new_window(im->mlx,
			im->window.size.x, im->window.size.y, "a");
	im->img = mlx_new_image(im->mlx, im->window.size.x, im->window.size.y);
	im->addr = mlx_get_data_addr(im->img, &im->bpp, &im->line_len, &im->endian);
	get_floor(im);
	get_tree(im);
	get_hole(im);
	get_sushi(im);
	get_snow(im);
	get_peng(im);
	get_igloo(im);
	return (*im);
}

void	put_game(t_image *im)
{
	put_floor(im);
	put_walls(im);
	put_player(im);
	put_exit(im);
	put_col(im);
	put_enemy(im);
	put_snow(im);
	mlx_string_put(im->mlx, im->window.addr, 9, 9, 3, conv_mv(im));
}

void	put_snow(t_image *img)
{
	int	i;

	i = 0;
	mlx_put_image_to_window(img->mlx,
		img->window.addr, img->snow, 0, img->spr_pos.y);
	mlx_put_image_to_window(img->mlx,
		img->window.addr, img->snow, 0, img->spr_pos.y + 128);
}

int	update_frame(void *param)
{
	t_image		*map;
	static int	frame;

	map = (t_image *)param;
	frame++;
	if (frame < ANIM_FRAME)
		map->spr_pos.y += 1;
	if (frame == ANIM_FRAME)
	{
		map->spr_pos.y = 0;
		frame = 0;
	}
	put_game(map);
	return (0);
}
