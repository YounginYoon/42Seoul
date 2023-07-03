/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:12:09 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:30:21 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_visited(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.visited = (int **)malloc(sizeof(int *) * game->map.height);
	while (i < game->map.height)
	{
		game->map.visited[i] = (int *)malloc(sizeof(int) * game->map.width);
		j = 0;
		while (j < game->map.width)
			game->map.visited[i][j++] = 0;
		i++;
	}
}

static void	get_map(t_game_info *game)
{
	char	*tmp;
	char	*free_buf;

	while (1)
	{
		tmp = get_next_line(game->map.fd);
		if (tmp == 0 || *tmp == '\n')
		{
			if (tmp != 0 && *tmp == '\n')
				free(tmp);
			break ;
		}
		free_buf = game->map.buf;
		game->map.buf = ft_strjoin(game->map.buf, tmp);
		free(tmp);
		free(free_buf);
		game->map.height++;
	}
}

static int	init_map_width(t_game_info	*game)
{
	char	**p;
	size_t	len_width;
	int		i;

	p = game->map.map_table;
	len_width = ft_strlen(p[0]);
	i = 1;
	while (p[i] != 0)
	{
		if (ft_strlen(p[i]) != len_width)
			return (0);
		else
			i++;
	}
	return ((int)len_width);
}

void	make_map(t_game_info *game, char *filename)
{
	init_map_player(game, filename);
	get_map(game);
	if (game->map.buf[0] == '\0' || game->map.buf[0] == '\n')
		print_map_error_message(6, game);
	game->map.map_table = ft_split(game->map.buf, '\n');
	game->map.width = init_map_width(game);
	init_visited(game);
	if (game->map.height < 3 || game->map.width == 0)
		print_map_error_message(5, game);
	if (close(game->map.fd) < 0)
		print_map_error_message(8, game);
}
