/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:13:28 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/26 18:09:42 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontal_wall_check(t_data *game)
{
	int	w;
	int	h;

	h = game->height;
	w = 0;
	while (w < game->width)
	{
		if (!(game->map[0][w] == 1 && game->map[h - 1][w] == 1))
			return (0);
		w++;
	}
	return (1);
}

int	vertical_wall_check(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	w = game->width;
	while (h < game->height)
	{
		if (!(game->map[h][0] == '1' && game->map[h][w - 1] == '1'))
			return (0);
		h++;
	}
	return (1);
}

void	check_map(t_data *game, int h, int w)
{
	char	c;

	c = game->map[h][w];
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != '\n')
	{
		ft_printf("\nError %c\n", c);
		exit_game(game);
	}
	if (c == 'C')
		game->collectible_cnt++;
	if (c == 'P')
		game->player_cnt++;
	if (c == 'E')
		game->exit_cnt++;
}
