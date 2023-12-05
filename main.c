/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:04:35 by eleleux           #+#    #+#             */
/*   Updated: 2022/12/17 13:33:46 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	mlx(t_image *im)
{
	mlx_hook(im->window.addr, 17, 0, *close_win, im);
	mlx_hook(im->window.addr, 3, 0, *input, im);
	mlx_loop_hook(im->mlx, *update_frame, im);
	mlx_loop(im->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	char	**path;
	t_image	im;

	if (ac == 2)
	{
		im.map = get_map(av[1]);
		if (!im.map.hei)
			return (-1);
		get_items(&im.map, 0, 0);
		path = allocate_path(im.map);
		check_path(path, im.map.pos_play.y, im.map.pos_play.x, im.map);
		if (!no_map_errors(im.map, path))
		{
			free_path(im.map.map);
			free_path(path);
			return (-1);
		}
		free_path(path);
		im.mlx = mlx_init();
		im = get_data_img(&im);
		mlx(&im);
		free_path(im.map.map);
	}
	return (0);
}
