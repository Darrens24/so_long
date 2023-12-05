/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:28:18 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/17 13:50:27 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_image *im)
{
	free_path(im->map.map);
	exit(0);
}

int	input(int keycode, void *param)
{
	t_image	*map;

	map = (t_image *)param;
	map->map.map[map->map.pos_play.y][map->map.pos_play.x] = '0';
	if (keycode == 53)
		close_win(map);
	if (keycode == 2
		&& map->map.map[map->map.pos_play.y][map->map.pos_play.x + 1] == '0')
	{
		map->map.pos_play.x++;
		map->mov_count++;
	}
	else if (keycode == 2
		&& map->map.map[map->map.pos_play.y][map->map.pos_play.x + 1] == 'C')
	{
		map->map.pos_play.x++;
		map->map.nb_col--;
		map->mov_count++;
	}
	else if (keycode == 2
		&& ((map->map.map[map->map.pos_play.y][map->map.pos_play.x + 1] == 'V')
		|| (map->map.map[map->map.pos_play.y][map->map.pos_play.x + 1] == 'E'
		&& map->map.nb_col == 0)))
		close_win(map);
	return (input2(keycode, param));
}

int	input2(int keycode, void *param)
{
	t_image	*map;

	map = (t_image *)param;
	if (keycode == 0
		&& map->map.map[map->map.pos_play.y][map->map.pos_play.x - 1] == '0')
	{
		map->map.pos_play.x--;
		map->mov_count++;
	}
	else if (keycode == 0
		&& map->map.map[map->map.pos_play.y][map->map.pos_play.x - 1] == 'C')
	{
		map->map.pos_play.x--;
		map->map.nb_col--;
		map->mov_count++;
	}
	else if (keycode == 0
		&& ((map->map.map[map->map.pos_play.y][map->map.pos_play.x - 1] == 'V')
		|| (map->map.map[map->map.pos_play.y][map->map.pos_play.x - 1] == 'E'
		&& map->map.nb_col == 0)))
		close_win(map);
	return (input3(keycode, param));
}

int	input3(int keycode, void *param)
{
	t_image	*map;

	map = (t_image *)param;
	if (keycode == 1
		&& map->map.map[map->map.pos_play.y + 1][map->map.pos_play.x] == '0')
	{
		map->map.pos_play.y++;
		map->mov_count++;
	}
	else if (keycode == 1
		&& map->map.map[map->map.pos_play.y + 1][map->map.pos_play.x] == 'C')
	{
		map->map.pos_play.y++;
		map->map.nb_col--;
		map->mov_count++;
	}
	else if (keycode == 1
		&& ((map->map.map[map->map.pos_play.y + 1][map->map.pos_play.x] == 'V')
		|| (map->map.map[map->map.pos_play.y + 1][map->map.pos_play.x] == 'E'
		&& map->map.nb_col == 0)))
		close_win(map);
	return (input4(keycode, param));
}

int	input4(int keycode, void *param)
{
	t_image	*map;

	map = (t_image *)param;
	if (keycode == 13
		&& map->map.map[map->map.pos_play.y - 1][map->map.pos_play.x] == '0')
	{
		map->map.pos_play.y--;
		map->mov_count++;
	}
	else if (keycode == 13
		&& map->map.map[map->map.pos_play.y - 1][map->map.pos_play.x] == 'C')
	{
		map->map.pos_play.y--;
		map->map.nb_col--;
		map->mov_count++;
	}
	else if (keycode == 13
		&& ((map->map.map[map->map.pos_play.y - 1][map->map.pos_play.x] == 'V')
		|| (map->map.map[map->map.pos_play.y - 1][map->map.pos_play.x] == 'E'
		&& map->map.nb_col == 0)))
		close_win(map);
	map->map.map[map->map.pos_play.y][map->map.pos_play.x] = 'P';
	return (0);
}
