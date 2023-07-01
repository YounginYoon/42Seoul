/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:08:05 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:29:40 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	return_row_direction(int i)
{
	int	move_row[4];

	move_row[0] = 0;
	move_row[1] = 0;
	move_row[2] = 1;
	move_row[3] = -1;
	return (move_row[i]);
}

static int	return_col_direction(int i)
{
	int	move_col[4];

	move_col[0] = 1;
	move_col[1] = -1;
	move_col[2] = 0;
	move_col[3] = 0;
	return (move_col[i]);
}

void	dfs(t_game_info *game, int row, int col)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < 4)
	{
		x = return_row_direction(i) + row;
		y = return_col_direction(i) + col;
		i++;
		if (x < 0 || y < 0 || x >= game->map.height
			|| y >= game->map.width || game->map.visited[x][y] == 1)
			continue ;
		if (game->map.map_table[x][y] != '1')
		{
			game->map.visited[x][y] = 1;
			dfs(game, x, y);
		}
	}
}
