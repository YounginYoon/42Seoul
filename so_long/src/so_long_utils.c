/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:07:25 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/28 20:44:31 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_length_extension(int filename_len, char *filename)
{
	if (filename_len < 5 || filename[filename_len - 5] == '/')
		print_filename_error(3);
	if (!(ft_strchr(filename, '.') \
		&& !ft_strncmp(ft_strchr(filename, '.'), ".ber", 5)))
		print_filename_error(2);
}

void	init_game(t_game_info *game, char *filename)
{
	make_map(game, filename);
	check_map_valid(game);
	init_mlx_load_image(game);
}

void	run_game(t_game_info *game)
{
	run_window(game);
	move_map(game);
	mlx_loop(game->mlx_controller.mlx);
}
