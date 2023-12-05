/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:49:30 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/09 15:30:39 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_sushi(t_image *im)
{
	im->sushi = mlx_xpm_file_to_image(im->mlx, "./sprites/crab64.xpm",
			&im->img_w, &im->img_h);
}

void	get_snow(t_image *im)
{
	im->snow = mlx_xpm_file_to_image(im->mlx, "./sprites/sno.xpm",
			&im->img_w, &im->img_h);
}
