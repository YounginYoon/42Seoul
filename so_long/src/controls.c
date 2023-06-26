/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:25:23 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/26 18:08:49 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_move(t_data *game, int h, int w)
{
	if (game->map[h][w] == 'E')
	{
		if (game->collectible_cnt != 0)
			return (0);
		ft_printf("\nYou have Won! Congrats!\n");
		exit_game(game);
	}
	if (game->map[h][w] == '0')
	{
		game->map[h][w] = 'P';
		game->x = w;
		game->y = h;
		game->step++;
	}
	if (game->map[h][w] == 'C')
	{
		game->map[h][w] = 'P';
		game->x = w;
		game->y = h;
		game->collectible_cnt--;
		game->step++;
	}
	return (1);
}

static int	keyboard_w_s(t_data *game, int cmd)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (cmd == 13)
	{
		if (game->map[--y][x] == '1')
			return (0);
		if (!check_move(game, y, x))
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (cmd == 1)
	{
		if (game->map[++y][x] == '1')
			return (0);
		if (!check_move(game, y, x))
			return (0);
		game->map[y - 1][x] = '0';
	}
	ft_printf("Steps: %d\n", game->step);
	ft_printf("Collectibles Left: %d\n", game->collectible_cnt);
	return (1);
}

static int	keyboard_a_d(t_data *game, int cmd)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (cmd == 0)
	{
		if (game->map[y][--x] == '1')
			return (0);
		if (!check_move(game, y, x))
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (cmd == 2)
	{
		if (game->map[y][++x] == '1')
			return (0);
		if (!check_move(game, y, x))
			return (0);
		game->map[y][x - 1] = '0';
	}
	ft_printf("Steps: %d\n", game->step);
	ft_printf("Collectibles Left: %d\n", game->collectible_cnt);
	return (1);
}

int	control_move(t_data *game, int cmd)
{
	int	check;

	if (cmd == 53)
	{
		exit_point(game);
	}
	if (cmd == 13 || cmd == 1)
		check = keyboard_w_s(game, cmd);
	if (cmd == 0 || cmd == 2)
		check = keyboard_a_d(game, cmd);
	if (check)
		update_game(game);
	return (1);
}
