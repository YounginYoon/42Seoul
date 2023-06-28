/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:08:52 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/28 19:12:18 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map(t_game_info *game, char *filename)
{
	game->map.height = 0;
	game->map.width = 0;
	game->map.fd = open(filename, O_RDONLY, 0644);
	if (game->map.fd < 0)
		print_filename_error(1);
	game->map.buf = ft_strdup("");
	game->map.map_table = 0;
	game->map.visited = 0;
	game->map.num_of_players = 0;
	game->map.num_of_exit = 0;
	game->map.num_of_collectible = 0;
}

static void	init_player(t_game_info	*game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.current_getting_collectible = 0;
	game->player.walk = 0;
}

void	init_mlx_load_image(t_game_info *game)
{
	int	img_width;
	int	img_height;

	game->mlx_controller.mlx = mlx_init();
	game->img.floor = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/floor.xpm", &img_width, &img_height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/wall.xpm", &img_width, &img_height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/exit.xpm", &img_width, &img_height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/collectible.xpm", &img_width, &img_height);
	game->img.player = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/player.xpm", &img_width, &img_height);
	game->mlx_controller.win = mlx_new_window(game->mlx_controller.mlx, \
	SCALE * game->map.width, SCALE * game->map.height, "so_long");
}

void	init_map_player(t_game_info *game, char *filename)
{
	init_map(game, filename);
	init_player(game);
}
