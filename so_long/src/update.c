/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:37:30 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:36:03 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (keycode == KEY_ESC)
		close_win(game);
	else if (keycode == KEY_A)
		move_player(game, -1, -1, 0);
	else if (keycode == KEY_S)
		move_player(game, game->map.width + 1, 0, 1);
	else if (keycode == KEY_D)
		move_player(game, 1, 1, 0);
	else if (keycode == KEY_W)
		move_player(game, (game->map.width + 1) * -1, 0, -1);
	if (x != game->player.x || y != game->player.y)
		ft_printf("walk : %d\n", ++(game->player.walk));
	return (0);
}

void	move_map(t_game_info *game)
{
	game->map.buf[(game->map.width + 1) \
	* game->player.y + game->player.x] = '0';
	mlx_hook(game->mlx_controller.win, KEY_PRESS_EVENT, 0, &key_hook, game);
	mlx_hook(game->mlx_controller.win, KEY_CLICK_EXIT, 0, &close_win, game);
}
