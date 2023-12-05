/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:13:01 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/17 13:41:02 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate_path(t_map map)
{
	char	**path;
	int		i;

	i = 0;
	path = malloc(sizeof(char *) * map.hei + 1);
	while (i < map.hei)
	{
		path[i] = ft_strdup(map.map[i]);
		i++;
	}
	path[i] = NULL;
	return (path);
}

void	put_enemy(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map.map[i])
	{
		j = 0;
		while (img->map.map[i][j])
		{
			if (img->map.map[i][j] == 'V')
				mlx_put_image_to_window(img->mlx,
					img->window.addr, img->hole, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_floor2(t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map.map[i])
	{
		j = 0;
		while (img->map.map[i][j])
		{
			if (img->map.map[i][j] == '0')
				mlx_put_image_to_window(img->mlx,
					img->window.addr, img->floor, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_tree(t_image *img)
{
	mlx_put_image_to_window(img->mlx,
		img->window.addr, img->tree, 0 * 64, 0 * 64);
}

char	*conv_mv(t_image *i)
{
	i->msg_mov = ft_itoa(i->mov_count);
	free(i->msg_mov);
	return (i->msg_mov);
}
