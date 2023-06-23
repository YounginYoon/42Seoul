/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:40:17 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/23 21:19:03 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_width(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i++;
	}
	if (line[i] == '\n')
		i--;

	return (i);
}

static int	add_line(t_data *game, char *newline)
{
	char	**tmp;
	int		i;

	if (!newline)
		return (0);
	i = 0;
	game->height++;
	tmp = (char **) malloc(sizeof(char *) * (game->height + 1));
	tmp[game->height] = NULL;
	while (i < game->height - 1)
	{
		tmp[i] = game->map[i++];
	}
	tmp[i] = newline;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

int	exit_game(t_data *game)
{
	int i;

	i = 0;
	if (game->winp)
		mlx_destroy_window(game->mlxp, game->winp);
	free(game->mlxp);
	while (i < game->height - 1)
	{
		free(game->map[i++]);
	}
	free(game->map);
	exit(0);
}

int	read_map(t_data *game, char **argv)
{
	char	*rdmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		rdmap = get_next_line(game->fd);
		if (!add_line(game, rdmap))
			break ;
	}
	close(game->fd);
	game->width = get_width(game->map[0]);
	return (1);
}
