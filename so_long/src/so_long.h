/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:08:07 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:31:05 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_PRESS_EVENT	2
# define KEY_CLICK_EXIT		17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define SCALE				64

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_map_info
{
	int		height;
	int		width;
	int		fd;
	char	*buf;
	char	**map_table;
	int		**visited;
	int		num_of_players;
	int		num_of_exit;
	int		num_of_collectible;
}	t_map_info;

typedef struct s_player_info
{
	int		x;
	int		y;
	int		current_getting_collectible;
	int		walk;
}	t_player_info;

typedef struct s_mlx_info
{
	void	*mlx;
	void	*win;
}	t_mlx_info;

typedef struct s_image_info
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*player;
}	t_image_info;

typedef struct s_game_info
{
	t_map_info		map;
	t_player_info	player;
	t_mlx_info		mlx_controller;
	t_image_info	img;
}	t_game_info;

int			main(int argc, char *argv[]);
void		check_file_length_extension(int filename_len, char *filename);
void		init_game(t_game_info *game, char *filename);
void		run_game(t_game_info *game);
void		make_map(t_game_info *game, char *filename);
void		run_window(t_game_info *game);
void		move_map(t_game_info *game);
void		check_map_valid(t_game_info *game);
void		print_filename_error(int error_num);
void		print_map_error_message(int error_num, t_game_info *game);
char		*free_memory(t_game_info *game);
void		init_map_player(t_game_info *game, char *filename);
void		dfs(t_game_info *game, int row, int col);
void		move_player(t_game_info *game, int next_step, int x_dir, int y_dir);
int			close_win(t_game_info *game);
void		init_mlx_load_image(t_game_info *game);
#endif
