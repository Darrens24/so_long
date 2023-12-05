/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:11:35 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/09 15:10:06 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_form(t_map map)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(map.map[i]);
	while (map.map[i] != NULL)
	{
		if ((int)ft_strlen(map.map[i]) != len && map.map[i])
		{
			ft_printf("Error\nMap isn't a rectangle.\n");
			return (0);
		}
		i++;
	}
	if (i <= 1)
	{
		ft_printf("Error\nMap isn't a rectangle.\n");
		return (0);
	}
	else if (i == 2 || len <= 2)
	{
		ft_printf("Error\nNot enough height/length to be a decent map.\n");
		return (0);
	}
	return (1);
}

int	check_walls(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.hei)
	{
		j = 0;
		while (j < map.len)
		{
			if (map.map[0][j] != '1'
			|| map.map[map.hei - 1][j] != '1'
			|| map.map[i][0] != '1'
			|| map.map[i][map.len - 1] != '1')
			{
				ft_printf("Error\nMap isn't surrounded by walls.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_items(t_map *map, int i, int j)
{
	while (i < map->hei)
	{
		j = 0;
		while (j < map->len)
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'P'
				&& map->map[i][j] != 'E' && map->map[i][j] != 'V')
			{
				ft_printf("Error\nForbidden characters\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (map->nb_play != 1 || map->nb_exit != 1 || map->nb_col < 1)
	{
		ft_printf("Error\n1 Player, 1 Exit and at least 1 Collectible\n");
		return (0);
	}
	return (1);
}

int	no_map_errors(t_map map, char **path)
{
	if (check_form(map) && check_walls(map)
		&& check_items(&map, 0, 0) && path_is_ok(path))
		return (1);
	return (0);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}
