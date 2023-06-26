/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:08:07 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/26 17:51:53 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_data
{
	int		fd;
	int		height;
	int		width;
	int		player_cnt;
	int		collectible_cnt;
	int		exit_cnt;
	int		x;
	int		y;
	int		step;

	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
	void	*mlxp;
	void	*winp;
}	t_data;

int		read_map(t_data *game, char **argv);
int		exit_game(t_data *game);
void	error_check(t_data *game);
int		horizontal_wall_check(t_data *game);
int		vertical_wall_check(t_data *game);
void	check_map(t_data *game, int h, int w);
int		control_move(t_data *game, int cmd);
void	update_player(t_data *game, int h, int w);
void	update_collectible(t_data *game, int h, int w);
void	update_wall(t_data *game, int h, int w);
void	update_exit(t_data *game, int h, int w);
void	update_floor(t_data *game, int h, int w);
void	load_images(t_data *game);
void	update_game(t_data *game);
#endif
