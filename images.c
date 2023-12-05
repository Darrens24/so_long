/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:01 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/09 14:39:50 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_floor(t_image *im)
{
	im->floor = mlx_xpm_file_to_image(im->mlx, "./sprites/snof.xpm",
			&im->img_w, &im->img_h);
}

void	get_tree(t_image *im)
{
	im->tree = mlx_xpm_file_to_image(im->mlx, "./sprites/t64.xpm",
			&im->img_w, &im->img_h);
}

void	get_peng(t_image *im)
{
	im->peng = mlx_xpm_file_to_image(im->mlx, "./sprites/realpeng.xpm",
			&im->img_w, &im->img_h);
}

void	get_hole(t_image *im)
{
	im->hole = mlx_xpm_file_to_image(im->mlx, "./sprites/hol.xpm",
			&im->img_w, &im->img_h);
}

void	get_igloo(t_image *im)
{
	im->igloo = mlx_xpm_file_to_image(im->mlx, "./sprites/igl64.xpm",
			&im->img_w, &im->img_h);
}
