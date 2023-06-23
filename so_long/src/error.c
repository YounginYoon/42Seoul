#include "so_long.h"

static int	horizontal_wall_check(t_data *game)
{
	int w;
	int h;

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

static int	vertical_wall_check(t_data *game)
{
	int h;
	int w;

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

static void	wall_check(t_data *game)
{
	int ver_wall;
	int hor_wall;

	ver_wall = vertical_wall_check(game);
	hor_wall = horizontal_wall_check(game);
	if (!ver_wall || !hor_wall)
	{
		printf("\nMissing walls\n");
		exit_game(game);
	}
}


static void	check_map(t_data *game, int h, int w)
{
	char c;

	c = game->map[h][w];
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != '\n')
	{
		printf("\nError %c\n", c);
		exit_game(game);
	}
	if (c == 'C')
		game->collectible_cnt++;
	if (c == 'P')
		game->player_cnt++;
	if (c == 'E')
		game->exit_cnt++;
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
	if (!(game->player_cnt == 1 && game->collectible_cnt > 1 && game->exit_cnt == 1))
	{
    printf("\nError\nSomething is wrong!\n");
    printf("either player, exit or collectible error!\n");
    exit_game(game);
	}
}

void	error_check(t_data *game)
{
	wall_check(game);
	check_map_valid(game);
}