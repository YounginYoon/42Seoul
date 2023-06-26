/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:12:23 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/26 18:09:07 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wall_check(t_data *game)
{
	int	ver_wall;
	int	hor_wall;

	ver_wall = vertical_wall_check(game);
	hor_wall = horizontal_wall_check(game);
	if (!ver_wall || !hor_wall)
	{
		ft_printf("\nMissing walls\n");
		exit_game(game);
	}
}

static void	check_map_valid(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->height - 1)
	{
		w = 0;
		while (w <= game->width)
		{
			check_map(game, h, w);
			w++;
		}
		h++;
	}
	if (!(game->player_cnt == 1
			&& game->collectible_cnt > 1
			&& game->exit_cnt == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("either player, exit or collectible error!\n");
		exit_game(game);
	}
}

void	error_check(t_data *game)
{
	wall_check(game);
	check_map_valid(game);
}
