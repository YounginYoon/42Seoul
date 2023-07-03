/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:13:28 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:29:27 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_object_walls(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (ft_strchr("01PEC", game->map.map_table[i][j]) == 0)
				print_map_error_message(0, game);
			if ((i == 0) || (i == game->map.height - 1)
				|| (j == 0) || (j == game->map.width - 1))
			{
				if (game->map.map_table[i][j] != '1')
					print_map_error_message(1, game);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	set_player_position_and_num_of_object(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_table[i][j] == 'P')
			{
				game->map.num_of_players++;
				game->player.x = i;
				game->player.y = j;
			}
			else if (game->map.map_table[i][j] == 'E')
				game->map.num_of_exit++;
			else if (game->map.map_table[i][j] == 'C')
				game->map.num_of_collectible++;
			j++;
		}
		i++;
	}
}

static void	check_num_of_object(t_game_info *game)
{
	if (game->map.num_of_players != 1)
		print_map_error_message(2, game);
	if (game->map.num_of_exit != 1)
		print_map_error_message(3, game);
	if (game->map.num_of_collectible < 1)
		print_map_error_message(7, game);
}

static int	check_dfs_valid(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.visited[i][j] == 0
				&& (game->map.map_table[i][j] == 'C'
				|| game->map.map_table[i][j] == 'E'))
				print_map_error_message(4, game);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map_valid(t_game_info *game)
{
	check_object_walls(game);
	set_player_position_and_num_of_object(game);
	check_num_of_object(game);
	game->map.visited[game->player.x][game->player.y] = 1;
	dfs(game, game->player.x, game->player.y);
	check_dfs_valid(game);
}
