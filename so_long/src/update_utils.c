/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:12:58 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:31:15 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_ground(t_game_info *game, int x_dir, int y_dir)
{
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.floor, game->player.x * SCALE, game->player.y * SCALE);
	game->player.x += x_dir;
	game->player.y += y_dir;
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.player, game->player.x * SCALE, game->player.y * SCALE);
}

static void	move_collectible(t_game_info *game, int x_dir, int y_dir)
{
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.floor, game->player.x * SCALE, game->player.y * SCALE);
	game->player.x += x_dir;
	game->player.y += y_dir;
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.floor, game->player.x * SCALE, game->player.y * SCALE);
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.player, game->player.x * SCALE, game->player.y * SCALE);
	game->player.current_getting_collectible++;
}

static void	move_exit(t_game_info *game, int x_dir, int y_dir)
{
	if (game->player.current_getting_collectible \
		== game->map.num_of_collectible)
	{
		ft_printf("you win! Congrats!\n");
		close_win(game);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.floor, \
		game->player.x * SCALE, game->player.y * SCALE);
		game->player.x += x_dir;
		game->player.y += y_dir;
		mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.player, \
		game->player.x * SCALE, game->player.y * SCALE);
	}
}

int	close_win(t_game_info *game)
{
	mlx_destroy_window(game->mlx_controller.mlx, game->mlx_controller.win);
	free_memory(game);
	exit(0);
}

void	move_player(t_game_info *game, int next_step, int x_dir, int y_dir)
{
	int	cur_offset;

	cur_offset = (game->map.width + 1) * game->player.y \
	+ game->player.x;
	if (game->map.buf[cur_offset + next_step] == '0')
		move_ground(game, x_dir, y_dir);
	else if (game->map.buf[cur_offset + next_step] == 'C')
	{
		move_collectible(game, x_dir, y_dir);
		game->map.buf[cur_offset + next_step] = '0';
	}
	else if (game->map.buf[cur_offset + next_step] == 'E')
		move_exit(game, x_dir, y_dir);
	if (game->map.buf[cur_offset] == 'E' && \
	game->map.buf[cur_offset + next_step] == '0')
		mlx_put_image_to_window(game->mlx_controller.mlx, \
	game->mlx_controller.win, game->img.exit, \
	(game->player.x - x_dir) * SCALE, (game->player.y - y_dir) * SCALE);
}
