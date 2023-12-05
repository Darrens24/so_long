/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:21:04 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/09 14:11:10 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map.map[i])
	{
		j = 0;
		while (img->map.map[i][j])
		{
			mlx_put_image_to_window(img->mlx,
				img->window.addr, img->floor, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_walls(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map.map[i])
	{
		j = 0;
		while (img->map.map[i][j])
		{
			if (img->map.map[i][j] == '1')
				mlx_put_image_to_window(img->mlx,
					img->window.addr, img->tree, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_player(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map.map[i])
	{
		j = 0;
		while (img->map.map[i][j])
		{
			if (img->map.map[i][j] == 'P')
				mlx_put_image_to_window(img->mlx,
					img->window.addr, img->peng, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_exit(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map.map[i])
	{
		j = 0;
		while (img->map.map[i][j])
		{
			if (img->map.map[i][j] == 'E')
				mlx_put_image_to_window(img->mlx,
					img->window.addr, img->igloo, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_col(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map.map[i])
	{
		j = 0;
		while (img->map.map[i][j])
		{
			if (img->map.map[i][j] == 'C')
				mlx_put_image_to_window(img->mlx,
					img->window.addr, img->sushi, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
