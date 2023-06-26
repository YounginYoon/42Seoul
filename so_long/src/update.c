/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:37:30 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/26 17:52:31 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_data *game)
{
	int	h;
	int	w;

	game->floor = mlx_xpm_file_to_image(game->mlxp,
			"assets/floor.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlxp,
			"assets/wall.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlxp,
			"assets/player.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlxp,
			"assets/exit.xpm", &w, &h);
	game->collectible = mlx_xpm_file_to_image(game->mlxp,
			"assets/collectible.xpm", &w, &h);
}

void	update_game(t_data *game)
{
	int	h;
	int	w;

	game->collectible_cnt = 0;
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->map[h][w])
		{
			if (game->map[h][w] == '1')
				update_wall(game, h, w);
			if (game->map[h][w] == 'C')
				update_collectible(game, h, w);
			if (game->map[h][w] == 'P')
				update_player(game, h, w);
			if (game->map[h][w] == 'E')
				update_exit(game, h, w);
			if (game->map[h][w] == '0')
				update_floor(game, h, w);
			w++;
		}
		h++;
	}
}
