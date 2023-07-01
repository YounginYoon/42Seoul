/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:37:59 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:30:40 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game_info *game, char ch, int *row, int *col)
{
	if (ch == '1')
		mlx_put_image_to_window(game->mlx_controller.mlx, \
	game->mlx_controller.win, game->img.wall, (*col) * SCALE, (*row) * SCALE);
	else if (ch == 'C')
	{
		mlx_put_image_to_window(game->mlx_controller.mlx, \
	game->mlx_controller.win, game->img.collectible, \
	(*col) * SCALE, (*row) * SCALE);
	}
	else if (ch == 'E')
		mlx_put_image_to_window(game->mlx_controller.mlx, \
game->mlx_controller.win, game->img.exit, (*col) * SCALE, (*row) * SCALE);
	else if (ch == 'P')
	{
		mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.player, \
		(*col) * SCALE, (*row) * SCALE);
		game->player.x = *col;
		game->player.y = *row;
	}
	else if (ch == '\n')
	{
		*col = -1;
		(*row)++;
	}
}

void	run_window(t_game_info *game)
{
	char	ch;
	int		index;
	int		row;
	int		col;

	index = 0;
	row = 0;
	col = 0;
	while (game->map.buf[index])
	{
		ch = game->map.buf[index++];
		if (ch != '\n')
			mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.floor, \
		(col) * SCALE, (row) * SCALE);
		put_image(game, ch, &row, &col);
		col++;
	}
}
