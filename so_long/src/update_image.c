/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:37:59 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/26 17:51:24 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_data *game, int h, int w)
{
	mlx_put_image_to_window(game->mlxp,
		game->winp, game->player, w * 40, h * 40);
	game->y = h;
	game->x = w;
}

void	update_collectible(t_data *game, int h, int w)
{
	mlx_put_image_to_window(game->mlxp,
		game->winp, game->collectible, w * 40, h * 40);
	game->collectible_cnt++;
}

void	update_wall(t_data *game, int h, int w)
{
	mlx_put_image_to_window(game->mlxp,
		game->winp, game->wall, w * 40, h * 40);
}

void	update_exit(t_data *game, int h, int w)
{
	mlx_put_image_to_window(game->mlxp,
		game->winp, game->exit, w * 40, h * 40);
}

void	update_floor(t_data *game, int h, int w)
{
	mlx_put_image_to_window(game->mlxp,
		game->winp, game->floor, w * 40, h * 40);
}
