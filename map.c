/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:58:57 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/17 13:44:37 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	number_of_lines(char *arg)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(arg, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}	

t_map	get_map(char *arg)
{
	int		fd;
	int		j;
	t_map	map;

	map.name = arg;
	if (!ft_strnstr((arg + ft_strlen(arg) - 4), ".ber", 4))
	{
		ft_printf("Error\nMap must be a .ber file\n");
		return (map);
	}
	map.hei = number_of_lines(arg);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_printf("Error\nNo file.\n");
	map.map = malloc(sizeof(char *) * (map.hei + 1));
	j = -1;
	while (++j < map.hei)
	{
		map.map[j] = get_next_line(fd);
		map.len = ft_strlen(map.map[j]);
		if (j != map.hei - 1)
			map.map[j][map.len - 1] = '\0';
	}
	map.map[j] = NULL;
	return (map);
}

void	get_items(t_map *map, int i, int j)
{
	while (i < map->hei)
	{
		j = 0;
		while (j < map->len)
		{
			if (map->map[i][j] == 'P')
			{
				map->pos_play.x = j;
				map->pos_play.y = i;
				map->nb_play++;
			}
			else if (map->map[i][j] == 'E')
			{
				map->pos_exit.x = j;
				map->pos_exit.y = i;
				map->nb_exit++;
			}
			else if (map->map[i][j] == 'C')
				map->nb_col++;
			j++;
		}
		i++;
	}
}

int	check_path(char **path, int i, int j, t_map map)
{
	if (i == map.pos_exit.y && j == map.pos_exit.x)
	{
		path[i][j] = 'x';
		return (1);
	}
	if (path[i][j] == '0' || path[i][j] == 'P' || path[i][j] == 'C')
	{
		path[i][j] = 'x';
		if (check_path(path, i, j + 1, map) == '0'
			|| check_path(path, i, j + 1, map) == 'C')
			return (1);
		if (check_path(path, i + 1, j, map) == '0'
			|| check_path(path, i + 1, j, map) == 'C')
			return (1);
		if (check_path(path, i - 1, j, map) == '0'
			|| check_path(path, i - 1, j, map) == 'C')
			return (1);
		if (check_path(path, i, j - 1, map) == '0'
			|| check_path(path, i, j - 1, map) == 'C')
			return (1);
	}
	return (0);
}

int	path_is_ok(char **path)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
	{
		j = 0;
		while (path[i][j])
		{
			if (path[i][j] == 'C')
			{
				ft_printf("Error\nSome collectibles are out of reach.\n");
				return (0);
			}
			else if (path[i][j] == 'E')
			{
				ft_printf("Error\nExit is out of reach.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
