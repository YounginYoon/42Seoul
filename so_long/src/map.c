/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:40:17 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/26 18:09:22 by youyoon          ###   ########seoul.kr  */
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
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = newline;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

static int	check_extension(char *file)
{
	unsigned long long	len;

	len = ft_strlen(file);
	if (len <= 4)
		return (1);
	if (file[len - 1] == 'r' && file[len - 2] == 'e' && \
		file[len - 3] == 'b' && file[len - 4] == '.')
		return (0);
	return (1);
}

int	read_map(t_data *game, char **argv)
{
	char	*rdmap;

	if (!check_extension(argv[1]))
	{
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
	else
	{
		ft_printf("\nWrong file extension\n");
		exit_game(game);
	}
}
